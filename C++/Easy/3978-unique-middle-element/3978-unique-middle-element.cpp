class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        return mp[nums[nums.size()/2]] == 1;
    }
};