/*
Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 1;	//Counter
        int cur = nums[0];		//Current candidate of majority element
        for (int i = 1; i < n; ++i) {
            if (cnt == 0) {		//Current counter is zero, should switch to another candidate (if the current element is the same as the candidate, this will act just as incrementing the counter)
                cur = nums[i];
                cnt = 1;
            } else if (cur == nums[i]) {//The current element is the same as the candidate
                ++cnt;
            } else {			//The current element is different from the candidate
                --cnt;
            }
            if (cnt == n / 2 + 1)	//Quit the loop in advance if already meet the requirement
                break;
        }
        return cur;
    }
};
