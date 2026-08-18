// class Solution {
// private:
//     int backtrack(int m,int n){
//         if(n == 0 || m == 0){
//             return 1;
//         }
//         return backtrack(m-1,n) + backtrack(m,n-1);
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return backtrack(m-1,n-1);
//     }
// };

// memoize

// class Solution {
// private:
//     vector<vector<int>> dp;
//     int backtrack(int m,int n){
//         if(n == 0 || m == 0){
//             return 1;
//         }
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
//         return dp[m][n] = (backtrack(m-1,n) + backtrack(m,n-1));
//     }
// public:
//     int uniquePaths(int m, int n) {
//         dp = vector<vector<int>> (m,vector<int>(n,-1));
//         return backtrack(m-1,n-1);
//     }
// };


// tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>> (m,vector<int>(n,1));
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

