class Solution {
public:
    long long maxWeight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int sol = 0;
        int n = nums.size();
        int itr = n-1;
        n /= 4;
        int t1 = (n+1)/2;
        int t2 = n/2;
        while(t1--){
            sol += nums[itr];
            itr--;
        }
        while(t2--){
            itr--;
            sol += nums[itr];
            itr--;    
        }
        return sol;
    }
};