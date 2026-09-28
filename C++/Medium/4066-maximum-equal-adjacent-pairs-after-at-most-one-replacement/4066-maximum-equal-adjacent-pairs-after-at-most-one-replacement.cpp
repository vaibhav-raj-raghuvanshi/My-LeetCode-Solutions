class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<long long int, int> mp;
        int n = nums.size();
        int sol = 0;
        int teq = 0;
        for(int i = 1; i < n; i++){
            long long int x1 = min(nums[i-1], nums[i]);
            long long int x2 = max(nums[i-1], nums[i]);
            long long int x = (x1 << 32) | x2;
            mp[x]++;
            if(nums[i-1] == nums[i]){
                teq++;
            }else{
                sol = max(sol, mp[x]);
            }
        }
        return sol + teq;
    }
};