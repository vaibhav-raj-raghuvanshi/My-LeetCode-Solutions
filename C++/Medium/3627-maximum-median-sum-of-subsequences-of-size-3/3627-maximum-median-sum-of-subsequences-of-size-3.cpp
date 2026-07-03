class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        long long sol = 0;
        while(low < high){
            low++;
            high--;
            sol += nums[high];
            high--;
        }
        return sol;
    }
};