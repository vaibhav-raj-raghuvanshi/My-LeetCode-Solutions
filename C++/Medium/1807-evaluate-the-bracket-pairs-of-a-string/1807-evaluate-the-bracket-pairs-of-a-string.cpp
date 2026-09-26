class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for(auto it : knowledge){
            mp[it[0]] = it[1];
        }
        string sol = "";
        string temp = "";
        bool flag = false;
        for(auto it : s){
            if(flag){
                if(it == ')'){
                    if(mp.count(temp) > 0){
                        sol.append(mp[temp]);
                    }else{
                        sol.push_back('?');
                    }
                    temp = "";
                    flag = false;
                }else{
                    temp.push_back(it);
                }
            }else{
                if(it != '('){
                    sol.push_back(it);
                }else{
                    flag = true;
                }
            }
        }
        return sol;
    }
};