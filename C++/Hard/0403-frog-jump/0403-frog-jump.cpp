class Solution {
private:
    vector<vector<int>> dp;
    int n;
    unordered_map<int, int> mp;
    bool backtrack(int idx, vector<int> &stones, int jump){
        if(idx < 0 || idx >= n){
            return false;
        }
        if(idx == n - 1){
            return true;
        }
        if(dp[idx][jump] != -1){
            return dp[idx][jump];
        }
        for(int k = -1; k<=1;k++){
            int nxt = jump + k;
            if(nxt <= 0){
                continue;
            }
            if(mp.count(stones[idx] + nxt)){
                if(backtrack(mp[stones[idx] + nxt], stones, nxt)){
                    return dp[idx][jump] = true;
                }
            }
        }
        return dp[idx][jump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        dp = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
        for(int i = 0;i < n;i++){
            mp[stones[i]] = i;
        }
        return backtrack(0, stones, 0);
    }
};