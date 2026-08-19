class Solution {
private:
    vector<vector<int>> dp;
    int backtrack(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0 || j == 0){
            return dp[i][j] = grid[i][j] + backtrack(max(i-1, 0), max(j-1, 0), grid); 
        }
        return dp[i][j] = grid[i][j] + min(backtrack(i-1, j, grid), backtrack(i, j-1, grid));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>> (n, vector<int> (m, -1));
        return backtrack(n-1, m-1, grid);
    }
};