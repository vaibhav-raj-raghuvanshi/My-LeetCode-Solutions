class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        unordered_map<char, int>mp;
        int sol = min(1, (int)nums.size());
        int low = 0;
        mp[nums[0]]++;
        for(int high = 1;high < nums.size();high++){
            mp[nums[high]]++;
            while(mp[nums[high]] > 1){
                mp[nums[low]]--;
                low++;
            }
            sol = max(high - low + 1, sol);
        }
        return sol;
    }
};