/*** 
	#136 Single Number
	Given an array of integers, every element appears twice except for one. Find that single one.

	Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
***/

class Solution {
	public:
    int singleNumber(vector<int>& nums) {
    	int N = nums.size();
    	int singleNumber = 0;
    	for(int i=0;i < N;i++){
    		singleNumber ^= nums[i];
    	}
        return singleNumber;
    }
};

/***
	O(N) complexity required, so cannot sort the vector. No extra memory required, so cannot use hash table.

	It is worth noticing that bit manipulation has some unique features. 

	x & 0 = 0;

	x | 0 = x;

	x ^ 0 = x;

	x & x = x;

	x | x = x;

	x ^ x = 0;

	For this problem, using XOR is quite straight-forward solution. 
	
	For all elements appeared even times would cancelled each other by XOR, but elements appeared odd times would remain.
***/
