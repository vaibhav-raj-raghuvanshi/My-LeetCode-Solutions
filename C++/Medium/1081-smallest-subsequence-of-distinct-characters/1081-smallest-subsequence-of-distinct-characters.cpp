class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        vector<bool> inAns(26,false);
        for(auto &it : s){
            mp[it]++;
        }

        string sol = "";
        for(auto &it : s){
            while(!inAns[it - 'a'] && sol.size() > 0 && sol.back() > it && mp[sol.back()] > 0){
                inAns[sol.back() - 'a'] = false;
                sol.pop_back();
            }
            mp[it]--;
            if(!inAns[it - 'a']){
                inAns[it - 'a'] = true;
                sol.push_back(it);
            }
        }

        return sol;
    }
};