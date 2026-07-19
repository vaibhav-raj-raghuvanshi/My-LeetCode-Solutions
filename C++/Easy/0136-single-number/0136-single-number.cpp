class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol = 0;
        for(auto &it : nums){
            sol ^= it;
        }
        return sol;
    }
};