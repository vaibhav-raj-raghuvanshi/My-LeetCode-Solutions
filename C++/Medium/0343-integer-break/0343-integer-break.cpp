class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3){
            return n-1;
        }
        int sol = 1;
        if(n % 3 == 1){
            sol = 4;
            n -= 4;
        }else if(n % 3 == 2){
            sol = 2;
            n -= 2;
        }
        return sol * pow(3, n/3);
    }
};