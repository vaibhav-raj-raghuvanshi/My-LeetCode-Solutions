class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long int> pre = {1};
        vector<long long int> mp(26, 0);
        long long int mod = 1e9 + 7;
        mp[(s[0] - 'a')]++;
        for(int i= 1;i < s.size();i++){
            pre.push_back((1 + pre[i-1] - mp[(s[i] - 'a')] + mod) % mod);
            mp[(s[i] - 'a')] += pre[i];
            mp[(s[i] - 'a')] %= mod;
            pre[i] += pre[i-1];
            pre[i] %= mod;
        }
        return pre.back();
    }
};