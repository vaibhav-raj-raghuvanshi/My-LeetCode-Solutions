class Solution {
public:
    int minInsertions(string s) {
        int need = 0;
        int sol = 0;
        for (char ch : s){
            if (ch == '('){
                if (need % 2 == 1){
                    sol++;
                    need--;
                }
                need += 2;
            }else{
                need--;
                if(need < 0){
                    sol++;
                    need = 1;
                }
            }
        }
        return sol + need;
    }
};