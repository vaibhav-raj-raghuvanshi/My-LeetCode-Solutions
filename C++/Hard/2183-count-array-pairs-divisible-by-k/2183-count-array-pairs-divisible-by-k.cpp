class Solution {
private:
    // for mutthi
    void add(int k, unordered_map<int, long long>& mp) {
        for(int i = 1; i * i <= k; i++){
            if(k % i == 0){
                mp[i]++;
                if(i != k / i)
                    mp[k / i]++;
            }
        }
    }
public:
    long long countPairs(vector<int>& nums, int k) {
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