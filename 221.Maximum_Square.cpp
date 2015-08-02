/*
No. 221 Maximum Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        int dp[m][n];   //Used to store the max square size if taking (i, j) as bottom right corner
        fill_n(&dp[0][0], m * n, 0);
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                result = 1;
            }
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                result = 1;
            }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                //Need to consider its 3 previous nearest positions' square size
                //If any of them is 0, indicating the char at that position is '0', the square size here cannot be larger than 1
                dp[i][j] = matrix[i][j] == '1' ? min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1 : 0;
                result = max(result, dp[i][j]);
            }
        return result * result;     //Need to return area, not size
    }
};
