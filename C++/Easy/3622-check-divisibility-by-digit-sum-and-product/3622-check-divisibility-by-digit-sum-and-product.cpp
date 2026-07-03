class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0,prod=1;
        int temp = n;
        while(temp){
            int t = temp%10;
            temp /=10;
            sum+=t;
            prod*=t;
        }
        if(n%(sum+prod)){
            return false;
        }
        return true;
    }
};