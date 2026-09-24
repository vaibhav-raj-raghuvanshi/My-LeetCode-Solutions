class Solution {
private:
    int digSum(int n){
        int sol = 0;
        while(n > 0){
            sol += n % 10;
            n /= 10;
        }
        return sol;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i < nums.size(); i++){
            if(i == digSum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};