class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        nums.push_back(k + 1);
        int low = 0, high = 0, n = nums.size(), sol = 0;
        long long int curr = 1;
        while(high < n){
            if(nums[high] >= k){
                long long int cnt = high - low;
                sol += (cnt * (cnt + 1) / 2);
                low = high + 1;
                curr = 1;
                high++;
                continue;
            }
            while(nums[high] * curr >= k){
                sol += (high - low);
                curr /= nums[low];
                low++;
            }
            curr *= nums[high];
            high++;
        }
        return sol;
    }
};