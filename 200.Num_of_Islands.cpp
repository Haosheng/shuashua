/***
	200. Number of Islands

	Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
	You may assume all four edges of the grid are all surrounded by water.
	
	Example 1:

	11110
	11010
	11000
	00000
	Answer: 1

	Example 2:

	11000
	11000
	00100
	00011
	Answer: 3
***/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        if(grid.size()==0) return 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    //bfs(grid, i,j);
                    res++;
                }
            }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r==grid.size() || c==grid[0].size() || r<0 || c<0){
            return;
        }
        if(grid[r][c]=='0'){
            return;
        }
        else{
            grid[r][c]='0';
            dfs(grid,r+1,c);
            dfs(grid,r,c+1);
            dfs(grid,r-1,c);
            dfs(grid,r,c-1);
        }
    }
};

/***
	A straight-forward search problem.
	At least we should check each box in the grid, so the runtime complexity is O(M*N) at best.
	One possible way of doing this is:
		when encounters a '1' box, increase the number of islands. 
			Then "flood" this island by changing all the adjacent '1' boxes into '0'.   
		Move to the next box until reach the right-bottom of the grid.

	In order to flood the found island, recall the well-known maze problem.
	We can use both DFS and BFS (BFS is not recommended here since we don't need an optimal result here) to solve the problem. The solution is simple.
***/