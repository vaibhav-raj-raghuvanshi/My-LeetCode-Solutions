class Solution {
public:
    int minAddToMakeValid(string s) {
        int sol = 0;
        int cnt = 0;
        for(auto it: s){
            if(it == '('){
                cnt++;
            }else{
                if(cnt == 0){
                    sol++;
                    cnt++;
                }
                cnt--;
            }
        }
        return sol + cnt;
    }
};