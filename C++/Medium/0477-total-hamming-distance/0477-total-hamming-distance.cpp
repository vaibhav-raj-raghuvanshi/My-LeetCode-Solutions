class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        vector<int> sol(33, 0);
        for(auto it : nums){
            int idx = 0;
            while(it > 0){
                if(it % 2 == 1){
                    sol[idx]++;
                }
                idx++;
                it /= 2;
            }
        }
        for(auto it : sol){
            total += (it * (n - it));
        }
        return total;
    }
};