/***
	40. Combination Sum II
	Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

	Each number in C may only be used once in the combination.
	
	Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.
	For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
	A solution set is: 
	[1, 7] 
	[1, 2, 5] 
	[2, 6] 
	[1, 1, 6]
***/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
    	vector<vector<int>> result;
    	vector<int> temp;
    	dfs(candidates, temp, result, target, 0, 0);
        return result;
    }
private:
	void dfs(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result, int target, int start, int sum){
		if(sum == result){
			result.push_back(temp);
			return;
		}
		int prev = -1;
		for(int i=start; i<candidates.size();i++){
			if(sum + candidates[i]>target) {return;}
			if(prev == candidates[i]) continue; // in the last iteration, we have already inserted candidates[i], so this time should skip the same number
			prev = candidates[i];
			temp.push_back(candidates[i]);
			dfs(candidates,temp,result,target,i+1,sum+candidates[i]);
			temp.pop_back();
		}
	}
}; 

/***
	Only minor change to 39. Combination Sum
	In this case, there might be duplicates in the candidates array. But we do not want the result to contain duplicates. Thus for one path, we should skip the duplicate element once we go back in a recursion.


	e.g
	candidates={1,1}, target = 1

	result should be {{1}} other than {{1},{1}}.

	However, every time we go deeper into the path (enter a new dfs recursion), we want to consider duplicate elements (1,1,1 and target=3), so refresh prev=-1 before the for loop.
***/


