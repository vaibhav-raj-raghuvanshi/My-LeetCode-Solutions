class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int prev = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            prev = shifts[i] = (prev + shifts[i]) % 26;
            s[i] = ((s[i] - 'a' + prev) % 26) + 'a';
        }
        return s;
    }
};