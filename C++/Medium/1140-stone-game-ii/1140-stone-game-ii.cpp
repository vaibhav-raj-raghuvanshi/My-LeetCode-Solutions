class Solution {
private:
    vector<vector<int>> dp;
    vector<int> suffix;

    int backtrack(int index, int M, vector<int>& piles){
        int n = piles.size();
        if(index >= n) {
            return 0;
        }
        if(2 * M >= n - index){
            return suffix[index];
        }
        if(dp[index][M] != -1){
            return dp[index][M];
        }
        int mx = 0;
        for(int x = 1; x <= 2 * M; x++){
            int opponent = backtrack(index + x, max(M, x), piles);
            int current = suffix[index] - opponent;
            mx = max(mx, current);
        }
        return dp[index][M] = mx;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        suffix.assign(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return backtrack(0, 1, piles);
    }
};