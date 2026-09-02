class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int sol = 0;
        int low = 0;
        int high = 0;
        int n = nums.size();
        unordered_map<char, int> mp;
        for(;high < n;high++){
            mp[nums[high]]++;
            while(mp[nums[high]] > 1){
                mp[nums[low]]--;
                low++;
            }
            sol = max(sol, high - low + 1);
        }
        return sol;
    }
};