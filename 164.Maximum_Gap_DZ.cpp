/***
    164. Maximum Gap

    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Try to solve it in linear time/space.

    Return 0 if the array contains less than 2 elements.

    You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
***/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
    if(nums.size()<2) return 0;
    int Max=nums[0],Min=nums[0],gap,numbkt,sizebkt;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>Max) Max=nums[i];
        if(nums[i]<Min) Min=nums[i];
    }
    gap=Max-Min;
    if(gap<2) return gap;
    sizebkt=(gap-1)/(nums.size()-1)+1;
    numbkt=gap/sizebkt+1;
    vector<list<int>> bucket(numbkt);
    for(int i=0;i<nums.size();i++){
        int index=(nums[i]-Min)/sizebkt;
        if(bucket[index].empty())
            bucket[index].push_back(nums[i]);
        else{
            auto it = bucket[index].begin();
            while(it!=bucket[index].end() && nums[i]>*it) it++;
            if(it==bucket[index].end()) bucket[index].push_back(nums[i]);
            else bucket[index].insert(it,nums[i]);
        }
    }
    int k=0;
    gap=0;
    int prev=bucket[0].back();
    for(int i=0;i<numbkt;i++){
        if(!bucket[i].empty()){
            int tmp = bucket[i].front()-prev;
            if(tmp>gap) gap=tmp;
            prev=bucket[i].back();
        }
    }
    return gap;
}
/***
    The problem requires linear time sort, so the options are limited to Bucket Sort or Radix Sort.

    Here I used Bucket Sort.

    First find out the range of the integer array, aka the Min and Max value. 

    The tricky part is how to define the bucket size and number of buckets. Since bucket sort complexity is O(n+k) where k is the number of buckets.

    We do not want very large k. In the mean time, we don't want the bucket size to be too large to contain to many elements inside.

    Be careful that the array could have duplicate elements. So we choose the bucket size to be (Max-Min-1)/(nums.size()-1)+1. (Why +1 at the end? duplication may make the nums.size()>>(Max-Min) )

    
    !!! The point of using bucket sort here is that within a bucket, we don't have to consider the gap. (think why)
    
    The gap would not be smaller than (Max-Min)/(nums.size()-1) (e.g {1,2,3},{1,1,1},{1,2,100}), so we just need to check the gap between the buckets to find the maximum gap.

***/
