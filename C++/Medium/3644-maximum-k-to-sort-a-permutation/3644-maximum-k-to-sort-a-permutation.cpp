class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int sol = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                if (sol == -1) sol = nums[i];
                else sol &= nums[i];
            }
        }
        if(sol == -1){
            return 0;
        }
        return sol;
    }
};