class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cnt0 = 0;
        int xr = 0;
        for(auto it : nums){
            xr ^= it;
            if(it == 0){
                cnt0++;
            }
        }
        if(cnt0 == nums.size()){
            return 0;
        }
        if(xr){
            return nums.size();
        }
        return nums.size() - 1;
    }
};