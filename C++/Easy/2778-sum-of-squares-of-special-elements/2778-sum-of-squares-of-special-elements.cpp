class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sq = floor(sqrt(n));
        int sol = 0;
        for(int i = 1; i <= sq; i++){
            if(n % i == 0){
                sol += nums[i-1] * nums[i-1];
                if(n/i != i){
                    sol += nums[n/i - 1] * nums[n/i - 1];
                }
            }
        }
        return sol;
    }
};