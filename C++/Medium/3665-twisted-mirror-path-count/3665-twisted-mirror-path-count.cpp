class Solution {
public:
    int n, m;
    long long int mod = 1e9 + 7;
    vector<vector<int>> nums;
    vector<vector<vector<long long int>>> dp;
    long long int dfs(int i, int j, int dir) {
        if(i >= n || j >= m){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        long long int &sol = dp[i][j][dir];
        if(sol != -1){
            return sol;
        }
        if(nums[i][j] == 1){
            if(dir == 0){
                sol = dfs(i+1, j, 1);
            }else{
                sol = dfs(i, j+1, 0);
            }
        }else{
            sol = (dfs(i, j+1, 0) + dfs(i+1, j, 1)) % mod;
        }

        return sol;
    }

    int uniquePaths(vector<vector<int>>& nums) {
        this->nums = nums;
        n = nums.size(), m = nums[0].size();
        dp.assign(n, vector<vector<long long int>>(m, {-1, -1}));
        return dfs(0, 0, 0);
    }
};