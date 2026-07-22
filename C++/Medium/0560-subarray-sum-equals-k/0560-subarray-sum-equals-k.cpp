class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long int sum = 0;
        int sol = 0;
        mp[0] = 1;
        for(auto it: nums){
            sum = sum + it;
            sol += mp[sum-k];
            mp[sum]++;
        }
        return sol;
    }
};