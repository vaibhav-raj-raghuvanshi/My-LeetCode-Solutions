class Solution {
public:
    unordered_map<int, int> dp;
    int backtrack(long long n){
        if(n == 0){
            return 0;
        }
        if(dp.count(n)){
            return dp[n];
        }
        if((n & (n - 1)) == 0){
            return dp[n] = 1;
        }
        int bits = bit_width((unsigned)n);
        long long low = 1LL << (bits - 1);
        long long high = 1LL << bits;
        return dp[n] = 1 + min(backtrack(n - low), backtrack(high - n));
    }

    int minOperations(int n) {
        return backtrack(n);
    }
};