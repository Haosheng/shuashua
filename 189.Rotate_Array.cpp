#METHOD = 2             //No. 0 and 1 has both 2n moves
#if (METHOD == 0)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;
        k = k % n;
        if (k == 0)
            return;
        auto mid = prev(nums.end(), k);
        reverse(nums.begin(), mid);
        reverse(mid, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
#else if (METHOD == 1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
private:
    //reverse the order within range
    void reverse(vector<int> &nums, int start, int end) {
        int temp = 0;
        while (start < end) {
            temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};
#else
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (nums.empty())
            return;
        k %= n;
        if (k == 0)
            return;
        
        int curStart = 0, count = n;    //keep a counter of letters already checked, so exactly n moves, no redundancy
        while (count != 0) {
            --count;
            int cur = (curStart + k) % n, temp = nums[curStart];
            //try to track what impact a letter moving to another position will cause
            while (cur != curStart) {
                int temp2 = nums[cur];
                nums[cur] = temp;
                temp = temp2;
                --count;
                cur = (cur + k) % n;
            }
            nums[curStart++] = temp;
        }
    }
};
#endif
