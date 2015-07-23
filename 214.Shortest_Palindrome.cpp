/*
No. 214 Shortest Palindrome

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

/*
Used two methods here: 0 for KMP, 1 for Manacher.
*/
#define METHOD 0
#if METHOD == 0
//using KMP algorithm
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int n = s.size();
        //create prefix array for the first half of s
        vector<int> t(n / 2);
        string subStr = s.substr(0, n / 2);
        createPre(subStr, t);
        int cur = n - 1, ref = 0, prev = - 1;
        while (cur >= 0) {
            if (s[cur] == s[ref]) {
                if (ref == n / 2 - 1)
                    break;
                ++ref;
                --cur;
            } else {
                prev = cur + t[ref - 1];
                if (ref == 0)
                    --cur;
                else {
                    //cur is pointing to the last letter of palindrome, rather than the first letter after the palindrome
                    ++prev;
                    ref = t[ref - 1];
                }
            }
        }
        if (prev == -1)
            return s;
        string result = s.substr(prev);
        reverse(result.begin(), result.end());
        result += s;
        return result;
    }
    
private:
    //create prefix array for KMP algorithm
    void createPre(string &s, vector<int> &t) {
        t[0] = 0;
        int cur = 1, ref = 0;
        while (cur < s.size()) {
            if (s[cur] == s[ref]) {
                t[cur++] = ++ref;   //t[cur] stores the number of identical letters in suffix comparing to prefix, that is, the position after the prefix
            } else if (ref != 0)
                ref = t[ref - 1];
            else
                t[cur++] = 0;
        }
    }
};
#endif
#if METHOD == 1
//Using Manacher's algorithm
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        //preprocessing the string for convenience in using Manacher's algorithm
        string str;
        str += '@';
        for (char c : s) {
            str += c;
            str += '#';
        }
        str = str.erase(str.size() - 1);
        str += '$';
        //implementing Manacher's algorithm
        vector<int> len(str.size());
        int c = 0, r = 0;   //current center and rightmost position
        //no sub-palindrome around the first two elements
        for (int i = 1; i < str.size() - 1; ++i) {
            len[i] = (r > i) ? min(len[c - i + c], r - i) : 0;
            while (i + len[i] + 1 < str.size() && i - len[i] - 1 >= 0 && str[i + len[i] + 1] == str[i - len[i] - 1])
                ++len[i];
            //the range needs updating
            if (i + len[i] > r) {
                c = i;
                r = i + len[i];
            }
        }
        //find the length of longest palindrome starting from the first letter
        int maxLen = 0;
        for (int i = 1; i < str.size(); ++i) {
            if (i == len[i] + 1 && len[i] > maxLen)
                maxLen = len[i];
        }
        //generate result
        string result = s.substr(maxLen + 1);
        reverse(result.begin(), result.end());
        result += s;
        return result;
    }
};
#endif
