class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ctrd = 1, ctri = 1, sol = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                ctri = ctrd = 1;
            }else if(nums[i] > nums[i-1]){
                ctri++;
                ctrd = 1;
            }else{
                ctrd++;
                ctri = 1;
            }
            sol = max({sol, ctri, ctrd});
        }
        return sol;
    }
};