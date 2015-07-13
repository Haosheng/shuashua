/*
Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        for (int num : nums)
            numsStr.push_back(to_string(num));
        //Sort the string vector
        sort(numsStr.begin(), numsStr.end(), comp);
        //Deal with special case
        if (numsStr[0] == "0")
            return "0";
        string result;
        for (auto str : numsStr)
            result += str;
        return result;
    }
    
private:
    //Must use static function for built-in sorting function
    static bool comp(const string &str1, const string &str2) {
        if (str1.size() == str2.size())
            return str1 > str2;                     //Built-in comparison function would be appropriate
        int idx = 0;
        for (; idx < str1.size() && idx < str2.size(); ++idx) {
            if (str1[idx] != str2[idx])             //Find the difference
                return str1[idx] > str2[idx];
        }
        //If one string is the prefix of the other, try recursion
        if (idx == str1.size()) {
            return comp(str1, str2.substr(idx));    //Seems like cannot use reference of some function results directly, unless adding "const"
        }
        else {
            return comp(str1.substr(idx), str2);
        }
    }
};
