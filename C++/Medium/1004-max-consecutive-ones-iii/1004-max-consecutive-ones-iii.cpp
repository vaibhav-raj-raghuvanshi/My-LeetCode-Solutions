class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0;
        map<int,int> mp;
        int high=1,low=0,temp=0;
        for(int high = 0 ;high<nums.size();high++){
            mp[nums[high]]++;
            while(mp[0]>k){
                mp[nums[low]]--;
                low++;
            }
            maxlen = max(maxlen,high-low+1);
        }
        return maxlen;
    }
};