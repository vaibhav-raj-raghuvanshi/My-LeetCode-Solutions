class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n , 0);
        stack<int> st;
        st.push(nums[n-1]);
        for(int i = n-2;i>=0; i--){
            while(!st.empty() && st.top() < nums[i]){
                sol[i]++;
                st.pop();
            }
            if(!st.empty() && st.top() > nums[i]){
                sol[i]++;
            }
            st.push(nums[i]);
        }
        return sol;
    }
};