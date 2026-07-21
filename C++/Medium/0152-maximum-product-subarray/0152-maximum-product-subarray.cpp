class Solution
{
public:
    int maxProduct(vector<int> &nums){
        int mx = nums[0], mn = nums[0];
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int tempMx = mx, tempMn = mn;
            if(nums[i] > 0){
                mx = max(nums[i], nums[i] * tempMx);
                mn = min(nums[i], nums[i] * tempMn);
            }else{
                mx = max(nums[i], nums[i] * tempMn);
                mn = min(nums[i], nums[i] * tempMx);
            }
            m = max(m, mx);
        }
        return m;
    }
};