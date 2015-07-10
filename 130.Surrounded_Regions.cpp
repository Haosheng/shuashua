/***
	130. Surrounded Regions

	Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

	A region is captured by flipping all 'O's into 'X's in that surrounded region.

	For example,
	X X X X
	X O O X
	X X O X
	X O X X
	After running your function, the board should be:

	X X X X
	X X X X
	X X X X
	X O X X
***/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        Row=board.size();
        Col=board[0].size();
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][Col-1]=='O'){
                dfs(board,i,Col-1);
            }
        }
        for(int j=1;j<Col-1;j++){
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[Row-1][j]=='O'){
                dfs(board,Row-1,j);
            }
        }
        for(int r=0;r<Row;r++)
            for(int c=0;c<Col;c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                else if(board[r][c]=='1'){
                    board[r][c]='O';
                }
            }
        return;
    }
private:
    int Row,Col;
    void dfs(vector<vector<char>>& bd, int r, int c){
            bd[r][c] ='1';
            if(r>1 && bd[r-1][c]=='O')
            dfs(bd,r-1,c);
            if(r<Row-2 && bd[r+1][c]=='O')
            dfs(bd,r+1,c);
            if(c>1 && bd[r][c-1]=='O')
            dfs(bd,r,c-1);
            if(c<Col-2 &&bd[r][c+1]=='O')
            dfs(bd,r,c+1);
    }
};

/***
	This problem is very similar with 200. Number of Islands
	It's easy to observe that an 'O' could remain iff it is connected to an 'O' lying on the four sides of the board.

	The algorithm for this problem is:
		Find all the 'O's that are connected to at least one 'O' on the four sides and mark these 'O's as '1'.
		Traverse the board:
			if the grid is 'O'
				this is a surrounded 'O', then change it to 'X'.
			if the grid is '1'
				this is a unsurrounded 'O', change it back to 'O'
			if the grid is 'X'
				do nothing
		return

	Now the problem becomes how to find all the 'O's that are unsurrounded. From the observation we have made, we should check each grid on the four sides.
	If there is a grid labeled 'O', then start to mark all the connected 'O's inside the four sides.
	This part is similar to 200. Number of Islands problem, use DFS would work.

	The code is simple.

***/