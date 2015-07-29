/*
No. 28 Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

//Using KMP algorithm

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        vector<int> backup(needle.size());
        backup[0] = 0;
        int pos = 1, cnd = 0;
        while (pos < needle.size()) {
            if (needle[pos] == needle[cnd]) {
                backup[pos] = ++cnd;    //So now backup[pos] stores the position to which candidate should return if the next candidate (cnd) and real char (pos) does not match. When returning, we should refer to current candidate's previous char's backup position. (It is a bit complex to store the returning position of current candidate directly, since that will be related to its previous char.)
                ++pos;
            } else if (cnd > 0) {
                cnd = backup[cnd - 1];  //Return to previous possible position.
            } else {
                backup[pos] = 0;
                ++pos;
            }
        }
        pos = 0, cnd = 0;
        while (pos < haystack.size()) {
            if (haystack[pos] == needle[cnd]) {
                ++pos;
                if (++cnd == needle.size()) //Found the needle
                    return pos - cnd;
            } else if (cnd > 0)
                cnd = backup[cnd - 1];
            else
                ++pos;
        }
        return -1;
    }
};
