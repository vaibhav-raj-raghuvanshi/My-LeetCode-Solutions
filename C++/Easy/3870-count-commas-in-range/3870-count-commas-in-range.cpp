class Solution {
public:
    int countCommas(int n) {
        long long int t = 1000;
        long long int ctr = 1, sol = 0;
        while(t <= n){
            if(t <= n/1000){
                sol += ctr * (t*1000 - t);
            }else{
                sol += ctr * (n - t + 1);
            }
            t *= 1000;
            ctr++;
        }
        return sol;
    }
};