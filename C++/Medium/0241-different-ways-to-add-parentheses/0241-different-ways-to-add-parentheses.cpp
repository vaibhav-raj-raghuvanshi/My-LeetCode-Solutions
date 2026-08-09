class Solution {
private:
    int solve(int it1, int it2, char ch){
        if(ch == '+'){
            return it1 + it2;
        }
        if(ch == '*'){
            return it1 * it2;
        }
        return it1 - it2;
    }
    vector<int> backtrack(int low, int high, string &str){
        vector<int> sol;
        for(int i= low;i <= high;i++){
            vector<int> lr, rr;
            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                lr = backtrack(low, i-1, str);
                rr = backtrack(i+1, high, str);
                for(auto &it1 : lr){
                    for(auto &it2: rr){
                        sol.push_back(solve(it1, it2, str[i]));
                    }
                }
            }
        }
        if(sol.empty()){
            sol.push_back(stoi(str.substr(low, high - low + 1)));
        }
        return sol;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return backtrack(0, expression.size()-1, expression);
    }
};