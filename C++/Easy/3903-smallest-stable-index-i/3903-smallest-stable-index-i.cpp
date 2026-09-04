class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preMax(n),suffMin(n);
        preMax[0] = nums[0];
        suffMin[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            preMax[i] = max(nums[i],preMax[i-1]);
            suffMin[n-1-i] = min(nums[n-1-i],suffMin[n-i]);
        }
        for(int i = 0;i<n;i++){
            if(preMax[i] - suffMin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};