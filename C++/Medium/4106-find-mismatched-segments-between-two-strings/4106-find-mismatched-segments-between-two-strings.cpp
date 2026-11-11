class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        string temp1 = "", temp2 = "";
        s1.push_back(' ');
        s2.push_back(' ');
        int n = s1.size();
        vector<vector<string>> sol;
        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i]){
                if(temp1.size()){
                    sol.push_back({temp1, temp2});
                }
                temp1 = "";
                temp2 = "";
            }else{
                temp1.push_back(s1[i]);
                temp2.push_back(s2[i]);
            }
        }
        return sol;
    }
};