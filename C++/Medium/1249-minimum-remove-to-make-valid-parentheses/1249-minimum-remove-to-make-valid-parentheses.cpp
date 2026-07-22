class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string sol = "";
        int cnt = 0;
        for(auto &it : s){
            if(it == '('){
                cnt++;
            }else if(it == ')'){
                cnt--;
            }else{
                continue;
            }
            if(cnt < 0){
                it = '-';
                cnt++;
            }
        }
        int i = s.size()-1;
        while(i >=0 && cnt > 0){
            if(s[i] == '('){
                s[i] = '-';
                cnt--;
            }
            i--;
        }
        for(auto it : s){
            if(it != '-'){
                sol.push_back(it);
            }
        }
        return sol;
    }
};