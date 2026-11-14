class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), sol = INT_MAX;
        vector<int> pre(n + 1);
        partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
        for(int i = l; i <= r; ++i){
            for(int j = 0; j + i <= n; ++j){
                int sum = pre[j + i] - pre[j];
                if(sum > 0){
                    sol = min(sol, sum);
                }
            }
        }
        if(sol == INT_MAX){
            sol = -1;
        }
        return sol;
    }
};