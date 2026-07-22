class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto it : s){
            if(st.empty() || st.top().first != it){
                st.push({it, 1});
            }else{
                if(st.top().second == k-1){
                    while(!st.empty() && st.top().first == it){
                        st.pop();
                    }
                }else{
                    st.push({it, st.top().second+1});
                }
            }
        }
        string sol = "";
        while(!st.empty()){
            sol.push_back(st.top().first);
            st.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};