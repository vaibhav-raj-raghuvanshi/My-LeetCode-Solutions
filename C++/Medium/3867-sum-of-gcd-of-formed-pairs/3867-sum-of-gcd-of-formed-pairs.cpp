class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> pre;
        int mx = 0;
        for(auto it : nums){
            mx = max(mx, it);
            pre.push_back(gcd(mx,it));
        }
        sort(pre.begin(), pre.end());
        int n = nums.size();
        long long sol = 0;
        for(int i = 0;i<n/2;i++){
            sol = sol + gcd(pre[i],pre[n-1-i]);
        }
        return sol;
    }
};