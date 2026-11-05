class Solution {
public:
    int titleToNumber(string str) {
        reverse(str.begin(), str.end());
        int sol = 0;
        while(!str.empty()){
            sol = - 64 + sol * 26 + str.back();
            str.pop_back();
        }
        return sol;
    }
};