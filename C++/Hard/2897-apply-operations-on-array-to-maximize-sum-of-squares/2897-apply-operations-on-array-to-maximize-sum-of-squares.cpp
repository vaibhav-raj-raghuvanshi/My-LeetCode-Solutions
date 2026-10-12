class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(31,0);
        for(int num:nums){
            for(int i=0;i<31;i++){
                if(num & (1<<i)) bits[i]++;
            }
        }
         int sum=0;
        int mod=1e9+7;
        while(k>0){
            long long curr=0;
            for(int i=0;i<31;i++){
                if(bits[i]>0){ 
                    curr=curr|(1LL<<i);
                    bits[i]--;
            }}
            long long rem=(curr*curr)%mod;
            sum=(sum+rem)%mod;
            k--;
        }
        return sum;
    }
};