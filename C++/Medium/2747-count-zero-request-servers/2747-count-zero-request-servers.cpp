class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end());
        int maxTime = 0;
        for (auto &q : queries){
            maxTime = max(maxTime, q);
        }
        vector<int> dp(maxTime + x + 3, 0);
        vector<int> curr(n+1, -1);

        for(auto &it : logs){
            int server = it[0];
            int time = min(it[1], maxTime + 1);
            int nextTime = min(time + x + 1, maxTime+x+2);
            if(time >= curr[server]){
                dp[time]++;
                dp[nextTime]--;
            }else{
                dp[curr[server]]++;
                dp[nextTime]--;
            }
            curr[server] = nextTime;
        }

        for(int i = 1;i < dp.size(); i++){
            dp[i]+=dp[i-1];
        }
        
        vector<int> sol;
        for(auto it : queries){
            sol.push_back(n - dp[it]);
        }
        return sol;
    }
};