class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<bool>> solArr(26,vector<bool>(26,false));
        vector<vector<bool>> pre(n,vector<bool>(26, false));
        vector<vector<bool>> suff(n,vector<bool>(26, false));
        pre[0][s[0] - 'a'] = true;
        suff[n-1][s[n-1] - 'a'] = true;
        for(int i = 1;i < n;i++){
            pre[i] = pre[i - 1];
            suff[n-i-1] = suff[n-i];
            pre[i][s[i] - 'a'] = true;
            suff[n-i-1][s[n-i-1] - 'a'] = true;
        }
        for(int i = 1; i < n-1; i++){
            for(int j = 0; j < 26; j++){
                if(pre[i-1][j] && suff[i+1][j]){
                    solArr[s[i] - 'a'][j] = true;
                }
            }
        }
        int sol = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j  <26;j++){
                if(solArr[i][j]){
                    sol++;
                }
            }
        }
        return sol;
    }
};