/*
No. 216 Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combSum(k, n, 1);
    }
    
private:
    //Assistive member function. Find the vector that meet the requirement of the problem, the minimum number in the set must be no less than start
    vector<vector<int> > combSum(int k, int n, int start) {
        vector<vector<int> > result;
        //Filter
        if (n < 0 || k > 9 || k < 1 || n / k > 9 || n / k < start)
            return result;
        if (k == 1) {
            //End of recursion
            vector<int> newVec;
            newVec.push_back(n);
            result.push_back(newVec);
        } else {
            for (int i = start; i < 10; ++i) {
                //Find the following numbers that can meet the requirement if we need the sets start with number i
                vector<vector<int> > temp = combSum(k - 1, n - i, i + 1);
                for (auto vec : temp) {
                    vec.insert(vec.begin(), i);
                    result.push_back(vec);
                }
            }
        }
        return result;
    }
};
