/***
	137. Single Number II
	Given an array of integers, every element appears three times except for one. Find that single one.

	Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

***/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<32;i++){
            int count = 0;
            for(int j=0;j<nums.size();j++){
                count+=((nums[j]>>i)&1);
            }
            int bit = (count%3>0)?1:0;
            result |= bit<<i;
        }
        return result;
    }
};

/***
	Treat each number as a 32 bit binary (0/1) array.
	e.g. nums = {2,2,3,2}
	nums[0]: 0000 0000 0000 0000 0000 0000 0000 0010
	nums[1]: 0000 0000 0000 0000 0000 0000 0000 0010
	nums[2]: 0000 0000 0000 0000 0000 0000 0000 0011
	nums[3]: 0000 0000 0000 0000 0000 0000 0000 0010

	now by adding each bit for the array, now we have:

	+
	count:   0000 0000 0000 0000 0000 0000 0000 0041

	then wipe out the mulitples of 3 on each bit

	%3
	bit:     0000 0000 0000 0000 0000 0000 0000 0011

	finally transfer bit back to integer and return.



	Note: count%3 may be 0,1,or 2. We should treat remainder 1 and 2 as 1 to the bit.
***/


/***
	How to count the number of '1's in a integer as binary number ?

	int count_ones(int num){
		for(int i=0;i<32;i++){
			count+=((num>>i)&1);
		}
		return count;
	}

	===============================================================

	How to transfer an array[32] of bit (0/1) to an integer ?

	int arr2int(const vector<int>& arr){
		int result = 0;
		for(int i=0;i<32;i++){
			result |= arr[i]<<i;
		}
		return result;
	}
***/