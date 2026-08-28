class Solution {
private:
    int n;
    bool isValid(string &word, string &pattern){
        vector<int> mp(26, -1), mpRev(26, -1);
        for(int i = 0;i < n; i++){
            int n1 = word[i] - 'a';
            int n2 = pattern[i] - 'a';
            if(mp[n1] == -1 && mpRev[n2] == -1){
                mp[n1] = n2;
                mpRev[n2] = n1;
            }else if(mp[n1] != n2 || mpRev[n2] != n1){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        n = pattern.size();
        vector<string> sol;
        for(auto word: words){
            if(isValid(word, pattern)){
                sol.push_back(word);
            }
        }
        return sol;
    }
};