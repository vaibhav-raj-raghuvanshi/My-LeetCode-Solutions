class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> mp(101, 0);
        for(auto &it : bulbs){
            mp[it]++;
        }
        vector<int> sol;
        for(int i = 1;i <= 100;i++){
            if(mp[i] % 2 == 1){
                sol.push_back(i);
            }
        }
        return sol;
    }
};