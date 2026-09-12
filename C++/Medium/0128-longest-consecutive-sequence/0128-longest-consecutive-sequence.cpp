class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
       int ans=0;
       for(auto it: nums){
       
       if( st.find(it-1)!=st.end()){
        continue;
       }
       int curr=1;
       while(!st.empty() && st.find(it+1)!=st.end()){
        curr++;
       // st.erase(it+1);
        it++;
       }
        ans=max(ans,curr);
       }
       return ans;
    }
};