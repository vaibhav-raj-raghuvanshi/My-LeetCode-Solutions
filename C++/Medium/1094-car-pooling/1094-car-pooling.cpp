class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> preSum(1002, 0);
        for(auto it : trips){
            preSum[it[1]] += it[0];
            preSum[it[2]] -= it[0];
        }
        if(preSum[0] > capacity){
            return false;
        }
        for(int i = 1; i <= 1000; i++){
            preSum[i] += preSum[i-1];
            if(preSum[i] > capacity){
                return false;
            }
        }
        return true;
    }
};