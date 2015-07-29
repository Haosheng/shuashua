/*
No. 5 Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

//Using Manacher's Algorithm

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        string str = "@";
        for (char c : s) {
            str += "#";
            str += c;
        }
        str += "#$";
        int len[str.size()];
        int c = 0;
        len[0] = 0;
	//It is much faster to seperate the cases before using while loop (from 168ms to 8ms)
        for (int i = 1; i < str.size(); ++i) {
            if (c + len[c] > i + len[c - i + c])
                len[i] = len[c - i + c];
            else if (c + len[c] - i > 0 && c + len[c] < i + len[c - i + c]) {
                len[i] = c + len[c] - i;	//len must be greater than 0
            } else {
                len[i] = (c + len[c] - i > 0) ? len[c - i + c] : 0;
                while (i - len[i] - 1 >= 0 && i + len[i] + 1 < str.size() && str[i - len[i] - 1] == str[i + len[i] + 1])
                    ++len[i];
                c = i;
            }
        }
        int start = 0, subLen = 0;
        for (int i = 1; i < str.size(); ++i) {
            if (subLen < len[i]) {
                subLen = len[i];
                start = (i - len[i] - 1) / 2;	//It doesn't matter whether subtract 1 or not, I think
            }
        }
        return s.substr(start, subLen);
    }
};
