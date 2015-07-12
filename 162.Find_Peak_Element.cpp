/*
No. 162 Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //deal with invalid vector and the case where there is only one element, INT_MIN
        if (n < 2)
            return (n - 1);
        //boundary cases
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return (n - 1);
        //not considering the two elements at the ends of the vector
        int low = 1, hi = n - 2;
        while (low < hi) {
            int mid = low + ((hi - low) >> 1);
            if (nums[mid] > nums[mid - 1]) {    //valid if mid > 0
                if (nums[mid] > nums[mid + 1])  //valid if mid < n - 1
                    return mid;
                else
                    low = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return low;
    }
};
