class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int idx = distance(nums.begin(), find(nums.begin(), nums.end(), 0));
        if (nums[(idx+1)%nums.size()] == 1) {
            for (int i=idx, j=0, prev=-1; j<nums.size(); j++, i++) {
                if (nums[i%nums.size()] != prev+1) return -1;
                prev = nums[i%nums.size()];
            }
            return min(idx, (int)nums.size()-idx+2);
        } else {
            for (int i=(idx+1)%nums.size(), j=0, prev=nums.size(); j<nums.size(); j++, i++) {
                if (nums[i%nums.size()] != prev-1) return -1;
                prev = nums[i%nums.size()];
            }
            return min(idx+2, (int)nums.size()-idx);
        }
        return -1;
    }
};