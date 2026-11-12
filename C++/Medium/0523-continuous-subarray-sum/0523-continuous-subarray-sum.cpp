class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prev = 0;
        for(int i = 0;i < nums.size(); i++){
            nums[i] += prev; 
            nums[i] %= k;
            if((++mp[nums[i]] >= 2 && nums[i] != prev) || (mp[nums[i]] > 2) || (nums[i] == 0 && i > 0)){
                return true;
            }
            prev = nums[i];
        }
        return false;
    }
};