class Solution {
public:
    int numberOfArrays(vector<int>& nums, long long int lower, long long int upper) {
        // 1 -3 4
        // 1 -2 2

        // 3 -4 5 1 -2
        // 3 -1 4 5 3 

        // lower - min, upper - max
        long long int mn = nums[0];
        long long int mx = nums[0];
        long long int n = nums.size();
        long long int curr = nums[0];
        for(int i = 1;i < n;i++){
            curr += nums[i];
            mn = min(mn, curr);
            mx = max(mx, curr);
        }
        return max(0ll, (min(upper, (upper - mx)) - max(lower, (lower - mn)) + 1));
        // -4 + 
    }
};