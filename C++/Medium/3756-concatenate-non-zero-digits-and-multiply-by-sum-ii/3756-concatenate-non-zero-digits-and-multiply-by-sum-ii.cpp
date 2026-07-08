class Solution {
private:
    vector<long long int> pw;
    long long int mod = 1e9+7;
    void setPow(int n){
        pw.push_back(1);
        for(int i = 0;i<n;i++){
            pw.push_back((pw.back()*10)%mod);
        }
    }
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        setPow(n);
        vector<long long int> cnt = {0};
        vector<long long int> num = {0};
        vector<long long int> sum = {0};
        for(auto it : s){
            long long int temp = it  - '0';
            if(temp == 0){
                cnt.push_back(cnt.back());
                num.push_back(num.back());
                sum.push_back(sum.back());
                continue;
            }
            cnt.push_back(cnt.back() + 1);
            num.push_back((num.back()*10 + temp) % mod);
            sum.push_back((sum.back() + temp) % mod);
        }

        vector<int> sol;
        for(auto it : queries){
            int st = it[0];
            int ed = it[1] + 1;
            sol.push_back((((num[ed] - ((num[st]*pw[cnt[ed] - cnt[st]]) % mod) + mod) % mod) * (sum[ed] - sum[st])) % mod);
        }
        return sol;
    }
};