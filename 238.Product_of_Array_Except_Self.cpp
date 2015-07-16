/***
	238. Product of Array Except Self

	Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

	Solve it without division and in O(n).

	For example, given [1,2,3,4], return [24,12,8,6].

	Follow up:
	Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
***/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<2) return nums;
        vector<int> res(nums.size(),nums[0]);
        for(int i=1;i<nums.size()-1;i++){
            res[i]=res[i-1]*nums[i];
        }
        int rt=1;
        for(int i=nums.size()-1;i>0;i--){
            res[i]=res[i-1]*rt;
            rt*=nums[i];
        }
        res[0]=rt;
        return res;
    }
};

/***
	just memorize the algo.

    e.g. nums={a,b,c,d}
    
    construct a vector of results: res={a,a,a,a}
    
    1. first traverse from front to end
    
        res[i] = res[i-1]*nums[i] 

        Thus res={a,ab,abc,abcd}

    2. second traverse from end to front

        append a right most integer to the vector, int rt = 1;

        for each iteration, rt *= nums[i], thus rt would be: 1, d, cd, bcd through the process of the second traverse.

        res[i] = res[i-1]*rt;

        Thus res = {a,acd,abd,abc}

    3. last set res[0] to the value of rt in the end : res[0] = rt = bcd

    Then res = {bcd, acd, abd, abc}

    Which is amazing.
***/