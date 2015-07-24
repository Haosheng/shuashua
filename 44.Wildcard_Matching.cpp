/*
No. 44 Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;   //double pointers
        int iPos = -1, jPos = -1;
        while (i < s.size()) {
            //directly matched
            if (j < p.size() && (s[i] == p[j] || p[j] == '?'))
                ++i, ++j;
            //if meets asterisk, record the position of it and corresponding position in s
            //then the asterisk does not directly participates in the matching, so we just skip it (j++)
            else if (j < p.size() && p[j] == '*') {
                iPos = i;
                jPos = j++;
            } else {    //do not match at certain point, or not enough letters in p
                //if asterisk has appeared, we should trace back to its position and try starting matching with s from another letter
                //for here we will choose the next letter in s
                if (jPos >= 0) {
                    i = ++iPos;
                    j = jPos + 1;
                } else
                    //there is no asterisk in p, so no tolerance for difference
                    return false;
            }
        }
        //check if p has unmatched letters in the end
        while (j < p.size())
            if (p[j++] != '*')
                return false;
        return true;
    }
};
