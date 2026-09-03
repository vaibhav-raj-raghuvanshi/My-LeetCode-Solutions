class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        stack<int> st;
        int n = nums.size();
        vector<int> sol(n, -1);
        for(int i = 0;i < n;i++){
            while(!st.empty() && st.top() <= nums[idx]){
                st.pop();
            }
            if(st.empty()){
                sol[idx] = -1;
            }else{
                sol[idx] = st.top();
            }
            st.push(nums[idx]);
            idx = (idx - 1 + n) % n;
        }
        return sol;
    }
};

// 1 2 3 4 5 3