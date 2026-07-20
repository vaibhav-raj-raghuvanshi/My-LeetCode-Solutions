class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mx = 0,n = nums.size();
        for(int i = 1;i<n;i++){
            mx = max(mx, nums[i] - nums[i-1]);
            nums[i] = min(nums[i],nums[i-1]);
        }
        return mx;
    }
};