class Solution {
private:
    int mod = 1337;
    int myPow(int base, int pw){
        base %= mod;
        int sol = 1;
        for(int i = 0; i < pw; i++){
            sol = (sol * base) % mod;
        }
        return sol;
    }
public:
    int superPow(int base, vector<int>& pw) {
        if(base == 1 || pw.empty()){
            return 1;
        }
        int ed = pw.back();
        pw.pop_back();
        return myPow(superPow(base, pw), 10) * myPow(base, ed) % mod;
    }
};