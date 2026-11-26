class Solution {
public:
    bool canAliceWin(int n) {

        // if()
        
        for(int i=10;i>=0;i--){
            if(n>=i){
                n-=i;
                continue;
            }

            if(i&1){
                return true;
            }else{
                return false;
            }
        }

        return true;

    }
};