class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double sol = sum/k;
        for(int i = k; i < nums.size(); i++){
            sum = sum - nums[i - k] + nums[i];
            sol = max(sol, sum/k);
        }
        return sol;
    }
};