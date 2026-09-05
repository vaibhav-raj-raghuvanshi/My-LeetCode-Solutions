class Solution {
public:
    int subarraysDivByK(vector<int>& nums, long long int k) {
        unordered_map<int, int> mp;
        int sol = 0;
        mp[0]++;
        nums[0] = ((nums[0]) % k + k) % k; 
        mp[nums[0]]++;
        if(nums[0] == 0){
            sol++;
        }
        int n = nums.size();
        for(int i = 1;i<n;i++){
            nums[i] = (((nums[i] + nums[i-1]) % k) + k) % k;
            sol += mp[nums[i]];
            mp[nums[i]]++;
        }
        return sol;
    }
};