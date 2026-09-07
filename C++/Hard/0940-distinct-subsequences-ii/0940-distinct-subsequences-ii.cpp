class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long int> pre = {1};
        map<char, long long int> mp;
        long long int mod = 1e9 + 7;
        mp[s[0]]++;
        for(int i= 1;i < s.size();i++){
            pre.push_back((1 + pre[i-1] - mp[s[i]] + mod) % mod);
            mp[s[i]] += pre[i];
            mp[s[i]] %= mod;
            pre[i] += pre[i-1];
            pre[i] %= mod;
        }
        return pre.back();
    }
};