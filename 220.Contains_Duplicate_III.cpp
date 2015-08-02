/*
No. 220 Contains Duplicate

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

//Using BST

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //If k == 0, i and j must be the same
        //Difference t must be non-negative
        if (k == 0 || nums.empty() || t < 0)
            return false;
        //Anti-overflow (INT_MAX - negative) //This is NASTY
        set<long long> rec; //Using set for BST
        int start = 0, cur = 0;
        //Build tree with consecutive (k + 1) elements
        while (cur < nums.size() && cur <= start + k) {
            if (!rec.insert(nums[cur++]).second)
                return true;    //Two elements of identical value, surely meets the requirement
        }
        //Check if elements in the initial tree meets the requirement
        //Only need to check its previous and next node in BST to get the smallest difference
        for (auto itr = rec.begin(); itr != rec.end(); ++itr) {
            if (itr != rec.begin() && abs(*itr - *(prev(itr, 1))) <= t)
                return true;
            if (itr != prev(rec.end(), 1) && abs(*itr - *(next(itr, 1))) <= t)
                return true;
        }
        //Check with later elements
        while (cur < nums.size()) {
            rec.erase(nums[start]);
            auto insertion = rec.insert(nums[cur]);
            if (!insertion.second)
                return true;    //Same value
            auto pos = insertion.first;
            if (pos != rec.begin() && abs(*pos - *(prev(pos, 1))) <= t)
                return true;
            if (pos != prev(rec.end(), 1) && abs(*pos - *(next(pos, 1))) <= t)
                return true;
            ++start, ++cur;
        }
        return false;
    }
};
