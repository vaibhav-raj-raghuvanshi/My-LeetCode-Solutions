class Solution {
public:
    string removeOuterParentheses(string s) {
        string sol = "";
        int curr = 0;
        for(auto it : s){
            if(it == '('){
                if(curr != 0){
                    sol.push_back(it);
                }
                curr++;
            }else{
                curr--;
                if(curr != 0){
                    sol.push_back(it);
                }
            }
        }
        return sol;
    }
};