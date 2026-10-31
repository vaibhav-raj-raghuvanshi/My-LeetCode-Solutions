class Solution {
public:
    int uniquePaths(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        long long int mod = 1e9 + 7;
        vector<long long int> dp(m, 0);
        dp[0] = 1;
        for(auto &row : nums) {
            long long int right = 0;

            for(int j = 0; j < m; j++) {
                if(row[j] == 1) {
                    swap(right, dp[j]);
                }else{
                    right = dp[j] = (right + dp[j]) % mod;
                }
            }
        }
        return dp[m-1];
    }
};