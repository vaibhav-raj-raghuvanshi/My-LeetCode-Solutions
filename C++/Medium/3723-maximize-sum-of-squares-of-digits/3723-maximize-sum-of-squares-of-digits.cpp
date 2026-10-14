class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string sol(num, '0');
        int i = 0;
        while(i < num && sum > 0){
            if(sum >= 9){
                sum -= 9;
                sol[i] = '9';
            }else{
                sol[i] = char(sum + '0');
                sum = 0;
            }
            i++;
        }
        if(sum > 0){
            return "";
        }
        return sol;
    }
};