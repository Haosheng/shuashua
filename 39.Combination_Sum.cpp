/***
	39. Combination Sum
	Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	The same repeated number may be chosen from C unlimited number of times.
	
	Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.
	For example, given candidate set 2,3,6,7 and target 7, 
	A solution set is: 
	[7] 
	[2, 2, 3] 
***/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(),candidates.end());
    	vector<vector<int>> result;
    	vector<int> temp;
    	dfs(candidates, temp, result, target, 0, 0);
        return result;
    }
private:
	void dfs(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result, int target, int start, int sum){
		if(sum == target) // find one solution set
		{
			result.push_back(temp);
			return;
		}

		for(int i=start; i < candidates.size(); i++){
			if(sum + candidates[i] > target) {return;} //prune
			temp.push_back(candidates[i]);
			dfs(candidates, temp, result, target, i, sum + candidates[i]);
			temp.pop_back(); //restore
		}
	}
};

/***
	Typical backtracking problem.
	The problem is to find all the paths to a certain destination.
	Start from the first element in the candidates array, when the current sum is smaller than the target, go deeper to next recursion. 

	When sum + candidates[i] > target, no need to go further since it's already too large. 

	When sum == target, then we got a path.

	Always remember to restore the status of the temp vector when getting out of a recursion.
***/