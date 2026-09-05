class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        if(n%2 == 1 && s[n/2] != 'f'){
            return false;
        }
        for(int i = 0; i < n/2; i++){
            if((s[i] == 'f' && s[n-i-1] == 'f') || (s[i] == 'n' && s[n-i-1] == 'v') || (s[i] == 'v' && s[n-i-1] == 'n')){
                continue;
            }
            return false;
        }
        return true;
    }
};