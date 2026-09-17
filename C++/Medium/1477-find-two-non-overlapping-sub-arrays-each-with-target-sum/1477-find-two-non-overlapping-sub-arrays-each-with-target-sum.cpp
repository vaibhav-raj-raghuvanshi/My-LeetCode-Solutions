class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> sol(n, 1e9);
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 1e9;
        if(nums[0] == target){
            sol[0] = 1;
        }
        mp[nums[0]] = 0;
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
            int currSol = 1e9;
            if(mp.count(nums[i] - target) > 0){
                currSol = i  - mp[nums[i] - target];
            }
            if(currSol != 1e9 && mp[nums[i] - target] != -1 &&sol[mp[nums[i] - target]] != 1e9){
                ans = min(ans, currSol + sol[mp[nums[i] - target]]);
            }
            sol[i] = min(sol[i-1], currSol);
            mp[nums[i]] = i;
        }
        if(ans == 1e9){
            ans = -1;
        }
        return ans;
    }
};