class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 1;
        int last = n%10;
        int temp = n;
        n = n/10;

        while(n > 0){
            prod *= (n % 10);
            n = n / 10;
        }
        int x = 10 - (last);
        for(int i = 0;i <= x;i++){
            if(((prod * (last+i)) % t) == 0){
                return temp + i;
            }
        }
        return temp + x;
    }
};