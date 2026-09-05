class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int sol = 0, n = nums.size();
        for(int i = 1; i < n;i++){
            if(nums[i] == nums[0]){
                sol++;
            }
        }
        for(int i = 1; i < n;i++){
            int contri = gcd(k, i);
            int req = k / contri;
            for(int j = 0;j < n;j+=req){
                if(j != i && nums[j] == nums[i]){
                    sol++;
                }
            }
        }
        return sol/2;
    }
};