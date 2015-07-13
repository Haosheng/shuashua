/*
Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*
Dividing the gap between max and min in the vector into nums.size() shares, each of which will be the minimum value of maximum gap.
Thus the maximum gap must exist between elements in different gap shares.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxN = INT_MIN, minN = INT_MAX;
	//Find the max and min element
        for (int num : nums) {
            if (num > maxN)
                maxN = num;
            if (num < minN)
                minN = num;
        }
	//Use two vectors to track the min and max values inside a certain interval
	//Using vector of doubles in case some element will have the value of INT_MAX/MIN
        vector<double> minI(n, INT_MAX + 0.1);
        vector<double> maxI(n, INT_MIN - 0.1);
        double interval = (double)(maxN - minN) / (n - 1);
        for (int num : nums) {
            int idx = (num - minN) / interval;
            minI[idx] = min((double)num, minI[idx]);
            maxI[idx] = max((double)num, maxI[idx]);
        }
	//Find the maximum gap between intervals
        int result = (int)interval, prev = maxI[0];
        for (int i = 1; i < n; ++i) {
            if (minI[i] != INT_MAX + 0.1) {	//If there is element within this interval
                result = (int)max((double)result, minI[i] - prev);
                prev = maxI[i];
            }
        }
        return result;
    }
};
