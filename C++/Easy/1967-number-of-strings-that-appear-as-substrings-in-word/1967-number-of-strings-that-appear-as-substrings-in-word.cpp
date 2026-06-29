class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sol = 0;
        for(auto it : patterns){
            if(word.find(it) != string::npos){
                sol++;
            }
        }
        return sol;
    }
};