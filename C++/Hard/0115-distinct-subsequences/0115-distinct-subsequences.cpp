class Solution {
public:
    int backtrack(string &str1, string &str2, int i1, int i2, vector<vector<int>> &dp){
        if (i2 == str2.size()){
            return 1;
        }
        if (i1 == str1.size()){
            return 0;
        }
        if (dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        int count = 0;
        if (str1[i1] == str2[i2]){
            count += backtrack(str1, str2, i1 + 1, i2 + 1, dp);
        }
        count += backtrack(str1, str2, i1 + 1, i2, dp);
        return dp[i1][i2] = count;
    }

    int numDistinct(string s, string t) {
        if (s.size() < t.size()){
            return 0;
        }
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return backtrack(s, t, 0, 0, dp);
    }
};