/*
No. 213 House Robber II

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        //n >= 3 guaranteed
        int dp0[n], dp1[n];
        //dp0 records the max value of not robbing the first house, dp1 records that of robbing the first house
        fill_n(dp0, n, 0);
        fill_n(dp1, n, 0);
        dp0[1] = nums[1];
        dp1[0] = nums[0], dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp0[i] = max(dp0[i - 1], dp0[i - 2] + nums[i]);
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        dp0[n - 1] = max(dp0[n - 2], dp0[n - 3] + nums[n - 1]);
        dp1[n - 1] = max(dp1[n - 2], dp1[n - 3]);   //when robbing the first house, robber cannot rob the last house
        return max(dp0[n - 1], dp1[n - 1]);
    }
};
