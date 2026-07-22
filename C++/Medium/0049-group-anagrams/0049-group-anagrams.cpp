class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto it : strs){
            string temp = it;
            sort(it.begin(),it.end());
            mp[it].push_back(temp);
        }
        vector<vector<string>> sol;
        for(auto it : mp){
            sol.push_back(it.second);
        }
        return sol;
    }
};