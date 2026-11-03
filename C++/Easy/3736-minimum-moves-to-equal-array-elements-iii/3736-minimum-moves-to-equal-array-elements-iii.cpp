class Solution {
public:
    int minMoves(vector<int>& nums) {
        return (nums.size() * ranges::max(nums)) - accumulate(nums.begin(), nums.end(), 0ll);
    }
};