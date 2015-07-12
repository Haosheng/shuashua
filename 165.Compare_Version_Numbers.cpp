/*
No. 165 Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t l1 = version1.size(), l2 = version2.size();
        size_t p1 = 0, p2 = 0;
        size_t p;	//used to track the number of digits in each level		
	//will cause runtime error if change p to a size_t pointer and change code below accordingly, dunno the reason
        for (; p1 < l1 || p2 < l2; ++p1, ++p2) {
            p = 0;
            int ver1 = (p1 >= l1) ? 0 : stoi(version1.substr(p1), &p);
            p1 += p;
            int ver2 = (p2 >= l2) ? 0 : stoi(version2.substr(p2), &p);
            p2 += p;
            if (ver1 > ver2)
                return 1;
            else if (ver1 < ver2)
                return -1;
        }
        return 0;
    }
};
