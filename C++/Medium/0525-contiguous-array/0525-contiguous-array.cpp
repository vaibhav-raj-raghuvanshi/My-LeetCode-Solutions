class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ctr = 0, n = nums.size(), sol = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;
        for(int i = 0;i < n; i++){
            if(nums[i] == 1){
                ctr++;
            }else{
                ctr--;
            }
            if(mp.count(ctr) == 0){
                mp[ctr] = i;
            }else{
                sol = max(sol, i - mp[ctr]);
            }
        }
        return sol;
    }
};