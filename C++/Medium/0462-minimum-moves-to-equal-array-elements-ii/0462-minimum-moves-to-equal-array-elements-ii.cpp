class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        int k = *mid;
        int sol = 0;
        for(auto it : nums){
            sol += abs(it - k);
        }
        return sol;
    }
};