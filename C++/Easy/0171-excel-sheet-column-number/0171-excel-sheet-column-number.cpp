class Solution {
public:
    int titleToNumber(string str) {
        reverse(str.begin(), str.end());
        int sol = 0;
        while(!str.empty()){
            sol = - 'A' + sol * 26 + str.back() + 1;
            str.pop_back();
        }
        return sol;
    }
};