class Solution {
private:
    int solve(vector<int> &nums){
        map<pair<int, int>, int> mp;
        int n = nums.size();
        int sol = 0;
        int teq = 0;
        for(int i = 1; i < n; i++){
            mp[{nums[i-1], nums[i]}]++;
            sol = max(sol, mp[{nums[i-1], nums[i]}]);
            if(nums[i-1] == nums[i]){
                teq++;
            }
        }
        sol = teq;
        for(int i = 1; i < n; i++){
            if(nums[i-1] != nums[i]){
                int currSol = teq + mp[{nums[i-1], nums[i]}] + mp[{nums[i], nums[i -1]}];
                sol = max(sol, currSol);
            }
        }
        return sol;
    }
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int sol = solve(nums);
        return sol;
    }
};