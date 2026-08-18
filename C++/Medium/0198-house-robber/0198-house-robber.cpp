class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size() - 3;
        int s1, s2;
        nums.push_back(0);
        while(n >= 0){
            nums[n] += max(nums[n+2], nums[n+3]);
            n--;
        }
        return max(nums[0], nums[1]);
    }
};