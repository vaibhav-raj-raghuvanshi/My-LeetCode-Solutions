class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        while(i < n && k > 0 && nums[i] <= 0){
            nums[i] = -nums[i];
            i++;
            k--;
        }
        return accumulate(nums.begin(), nums.end(), 0ll) - (k % 2) * 2 * *min_element(nums.begin(), nums.end());
    }
};