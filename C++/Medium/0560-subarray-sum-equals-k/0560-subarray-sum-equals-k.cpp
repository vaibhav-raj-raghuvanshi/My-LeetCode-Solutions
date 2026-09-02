class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sol = 0;
        if(nums[0] == k){
            sol++;
        }
        // mp[0]++;
        mp[nums[0]]++;
        for(int i = 1; i < n;i++){
            nums[i] += nums[i-1];
            sol += mp[nums[i] - k] + (nums[i] == k);
            mp[nums[i]]++;
        }
        return sol;
    }
};