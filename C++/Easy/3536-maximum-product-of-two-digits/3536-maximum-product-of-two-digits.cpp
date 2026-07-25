class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            if(temp > mx1){
                mx2 = mx1;
                mx1 = temp;
            }else if(temp > mx2){
                mx2 = temp;
            }
        }
        return mx1* mx2;
    }
};