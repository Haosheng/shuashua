/***
	239. Sliding Window Maximum
	Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

	For example,
	Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

	Window position                Max
	---------------               -----
	[1  3  -1] -3  5  3  6  7       3
	 1 [3  -1  -3] 5  3  6  7       3
	 1  3 [-1  -3  5] 3  6  7       5
	 1  3  -1 [-3  5  3] 6  7       5
	 1  3  -1  -3 [5  3  6] 7       6
	 1  3  -1  -3  5 [3  6  7]      7
	Therefore, return the max sliding window as [3,3,5,5,6,7].

	Note: 
	You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
***/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

/***
	There is a data structure called monotonic queue which is designed for sliding window problem.

	Monotonic queue requires a deque container. Deque is a double-sided queue where you can push and pop from both ends.

	The core thought is as follows:

	Use the deque to store the index of number. When the window sildes one position, there are several possible cases to consider:

	e.g. current window is [1,5,1,2] and the max number is 5. The next number is 3. In the deque, the front value is the index of "5" which is 1. So when we move one position,

	this value is still valid in the window, no need to pop this.

	The next number is 3, so for the rest number in the deque, if it is smaller than 3, it will never become a max number in a window. (think why)

	So in the deque, pop all the number smaller than 3 from the back. 

	Then insert 3 into the deque.

	Last push the front of the deque to the result.

***/