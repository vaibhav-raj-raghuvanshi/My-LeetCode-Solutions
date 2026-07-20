class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        nums.push_back(0);
        for(int i = n-3;i>=0;i--){
            nums[i]+=max(nums[i+2],nums[i+3]);
        }
        return max(nums[0],nums[1]);
    }
};