/*
No. 93 Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

//Obvious DFS solution
//Be careful when checking whether a number is legit (leading 0s, out of bound)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string path;
        dfs(s, path, 0, 0, result);
        return result;
    }
    
private:
    void dfs(string &s, string &path, int count, int start, vector<string> &result) {
        //already made sure that start is within range
        //trimming, return in advance when encountering obviously impossible cases
        if (s.size() - start > (4 - count) * 3 || s.size() - start < 4 - count)
            return;
        //add current ip to result if got all 4 numbers
        if (count == 4) {
            path.erase(path.size() - 1);
            result.push_back(path);
            path += '.';        //for the convenience of regular erasing the last added components
            return;
        }
        //try 3 number of digits
        for (int i = 1; i < 4; ++i) {
            //no legit nonzero number should start with 0
            if (s[start] == '0')
                if (i > 1)
                    break;
            //make sure we have a legal index for next level
            if (start + i <= s.size()) {
                //check if current number is legit
                if (i < 3 || stoi(s.substr(start, i)) <= 255) {
                    path += s.substr(start, i);
                    path += '.';
                    dfs(s, path, count + 1, start + i, result);
                    path.erase(path.size() - i - 1);
                }
            }
        }
    }
};
