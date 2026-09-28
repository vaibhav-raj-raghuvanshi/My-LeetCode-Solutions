class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mp;
        int n = nums.size();
        int sol = 0;
        int teq = 0;
        for(int i = 1; i < n; i++){
            mp[{min(nums[i-1], nums[i]), max(nums[i], nums[i-1])}]++;
            if(nums[i-1] == nums[i]){
                teq++;
            }else{
                sol = max(sol, mp[{min(nums[i-1], nums[i]), max(nums[i], nums[i-1])}]);
            }
        }
        return sol + teq;
    }
};