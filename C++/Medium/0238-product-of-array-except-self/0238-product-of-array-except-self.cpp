class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1), suff(n + 1);
        pre[0] = 1;
        suff[n] = 1;

        for(int i = 0;i<n;i++){
            pre[i + 1] = nums[i] * pre[i];
            suff[n - i - 1] = nums[n-i-1] * suff[n - i];
        }

        vector<int> sol;
        for(int i = 0;i < n;i++){
            sol.push_back(pre[i] * suff[i+1]);
        }
        return sol;
    }
};