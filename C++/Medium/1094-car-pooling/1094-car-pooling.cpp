class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> preSum(1002, 0);
        for(auto it : trips){
            preSum[it[1] + 1] += it[0];
            preSum[it[2] + 1] -= it[0];
        }

        for(int i = 1; i <= 1001; i++){
            preSum[i] += preSum[i-1];
            if(preSum[i] > capacity){
                return false;
            }
        }
        return true;
    }
};