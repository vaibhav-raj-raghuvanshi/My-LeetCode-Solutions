class Solution {
public:
    int reverseDegree(string s) {
        int sol = 0;
        for(int i = 0;i < s.size();i++){
            sol += ((i+1) * (26 - (s[i] - 'a')));
        }
        return sol;
    }
};