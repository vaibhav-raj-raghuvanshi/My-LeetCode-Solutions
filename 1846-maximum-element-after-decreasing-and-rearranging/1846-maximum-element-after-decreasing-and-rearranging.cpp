class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n+1,0);
        for(auto it : nums){
            mp[min(it, n)]++;
        }
        int sol = 0;
        for(int i = 1;i<=n;i++){
            sol = min(i, sol + mp[i]);
        }
        return sol;
    }
};