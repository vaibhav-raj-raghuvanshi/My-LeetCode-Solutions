class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // sort(nums)
        int sum = nums[0];
        int temp = nums[0];
        unordered_map<int, int> mp;
        mp[nums[0]]++;
        int i;
        for(i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1] + 1){
                temp += nums[i];
            }else{
                break;
            }
            mp[nums[i]]++;
            sum = max(sum, temp);
        }
        for(;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(mp[sum] > 0){
            sum++;
        }
        return sum;
    }
};