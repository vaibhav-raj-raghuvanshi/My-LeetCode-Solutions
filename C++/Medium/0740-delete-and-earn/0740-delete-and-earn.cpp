class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<long long int> sol(20001, 0);
        for(auto it : nums){
            sol[it] += it;
        }
        for(int i = 3;i<20001;i++){
            sol[i] += max(sol[i-2], sol[i-3]);
        }
        return max(sol[20000], sol[19999]);
    }
};