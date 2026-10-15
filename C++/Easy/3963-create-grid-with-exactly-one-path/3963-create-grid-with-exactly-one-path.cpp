class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string str;
        for(int i = 0; i < n ;i++){
            str.push_back('#');
        }
        vector<string> sol(m, str);
        for(int i = 0; i < m; i++){
            sol[i][0] = '.';
        }
        for(int i = 0; i < n; i++){
            sol[m - 1][i] = '.';
        }
        return sol;
    }
};