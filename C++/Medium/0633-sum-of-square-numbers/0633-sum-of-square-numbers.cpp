class Solution {
private:
    bool isPerf(int n){
        int t = sqrt(n);
        return t*t == n;
    }
public:
    bool judgeSquareSum(int c) {
        long long int x = 0, y = c;
        while(x <= y){
            if(isPerf(y)){
                return true;
            }
            x++;
            y = c - x * x;
        }
        return false;
    }
};