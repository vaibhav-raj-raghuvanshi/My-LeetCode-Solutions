class Solution {
private:
    vector<string> sol;
    void backtrack(int o, int c, string &temp){
        if(c < o || o < 0 || c < 0){
            return;
        }
        if(o == 0 && c == 0){
            sol.push_back(temp);
        }
        temp.push_back('(');
        backtrack(o - 1, c, temp);
        temp.pop_back();
        temp.push_back(')');
        backtrack(o, c - 1, temp);
        temp.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        backtrack(n, n, temp);
        return sol;
    }
};