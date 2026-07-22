class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int left = nums[0];
        int right = nums[n-1];
        int low = 1,high = n-2;
        int sol = 0;
        while(low <= high){
            if(left <= right){
                left = max(left,nums[low]);
                sol += left - nums[low];
                low++;
            }else{
                right = max(right,nums[high]);
                sol += right - nums[high];
                high--;
            }
        }
        return sol;
    }
};