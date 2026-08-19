class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
        prev[0] = nums[0][0];
        for(int i = 1; i < n; i++){
            curr[0] = prev[0] + nums[i][0];
            for(int j = 1; j <= i; j++){
                curr[j] = nums[i][j] + min(prev[j], prev[j-1]);
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};