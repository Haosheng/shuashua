/***
	179. Largest Number
	Given a list of non negative integers, arrange them such that they form the largest number.

	For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

	Note: The result may be very large, so you need to return a string instead of an integer.
***/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> num_str(nums.size());
        for(int i=0;i<nums.size();i++){
            num_str[i]=to_string(nums[i]);
        }
        sort(num_str.begin(),num_str.end(),compare_str);
        for(auto str:num_str)
            result+=str;
        if(result[0]=='0') return "0";
        return result;
    }
private:
    static bool compare_str(string a, string b){
        return (a+b)>(b+a);
    }
};

/***
	The catch for this problem is to implement a comparator for string concatenaiton.

	How to compare 3 and 30 in this context?

	Obviously 3 should come before 30 since 330>303.

	So the comparator is bool comp(string a, string b){return a+b>b+a;}

	Note:

	1. In order to call the compare_str function without instantiating a Solution Object, you MUST make the function STATIC!!!

	2. If the array is filled with 0, you should return "0" instead of "0...0"s to make sense.
***/