class Solution {
private:
    vector<int> spf;
    void init(){
        for(int i = 0;i < 100001;i++){
            spf.push_back(i);
        }
        for(int i = 2; i*i <= 100001;i++){
            if(spf[i] != i){
                continue;
            }
            int num = i * i;
            while(num < 100001){
                spf[num] = i;
                num += i;
            }
        }
    }
    void add(int k, unordered_map<int, long long>& mp) {
        vector<pair<int, int>> factors;
        while (k > 1) {
            int p = spf[k];
            int cnt = 0;
            while (k % p == 0) {
                k /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
        vector<int> divisors = {1};
        for (auto [p, cnt] : factors) {
            int sz = divisors.size();
            int power = 1;
            for (int e = 1; e <= cnt; e++) {
                power *= p;
                for (int i = 0; i < sz; i++) {
                    divisors.push_back(divisors[i] * power);
                }
            }
        }
        for (int d : divisors) {
            mp[d]++;
        }
    }
public:
    long long countPairs(vector<int>& nums, int k) {
        init();
        unordered_map<int, long long int> mp;
        long long int sol = 0;
        for(auto it : nums){
            int contri = gcd(it, k);
            int req = k/contri;
            sol += mp[req];
            add(it, mp);
        }
        return sol;
    }
};