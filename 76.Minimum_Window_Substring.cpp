/*
No. 76 Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int MAX = 256;
        int dict[MAX], rec[MAX];        //this is way faster than using unordered_map (find and count takes too much time)
        fill_n(dict, MAX, 0);
        fill_n(rec, MAX, 0);
        //build dictionary
        for (char c : t)
            ++dict[c];
        int count = 0, start = 0, cur = 0, minLen = INT_MAX, pos = s.size();
        for (; cur < s.size(); ++cur) {
            //current char is in string t
            if (dict[s[cur]] > 0) {
                if (rec[s[cur]] < dict[s[cur]])
                    ++count;
                ++rec[s[cur]];
                //find the starting point
		//since the found substring can contain duplicate required letters (eg: s = "caae", t = "cae"), we must search from the start, rather than caring about the case at current position, like we did in Substring with Concatenation of All Words
                while (rec[s[start]] == 0 || rec[s[start]] > dict[s[start]]) {
                    if (rec[s[start]] > 0) {
                        --rec[s[start]];
                        if (rec[s[start]] < dict[s[start]])
                            --count;
                    }
                    ++start;
                }
                if (count == t.size() && (cur - start + 1 < minLen)) {
                    minLen = cur - start + 1;
                    pos = start;
                }
            }
        }
        string result = s.substr(pos, minLen);
        return result;
    }
};
