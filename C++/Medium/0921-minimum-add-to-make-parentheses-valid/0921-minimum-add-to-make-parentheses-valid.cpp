class Solution {
public:
    int minAddToMakeValid(string s) {
        int sol = 0;
        for(auto it: s){
            if(it == '('){
                sol++;
            }else{
                sol--;
            }
        }
        return abs(sol);
    }
};