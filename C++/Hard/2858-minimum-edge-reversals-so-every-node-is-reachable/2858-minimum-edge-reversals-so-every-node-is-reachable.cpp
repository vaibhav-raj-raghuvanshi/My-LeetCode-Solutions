class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> dp, sol, vis;
    void dfs1(int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            int child = it.first;
            int cost = it.second;
            if(vis[child]){
                continue;
            }
            dfs1(child);
            dp[node] += dp[child] + cost;
        }
    }
    void dfs2(int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            int child = it.first;
            int cost = it.second;
            if(vis[child]){
                continue;
            }
            if(cost == 1){
                sol[child] = sol[node] - 1;
            }else{
                sol[child] = sol[node] + 1;
            }
            dfs2(child);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        dp.assign(n, 0);
        sol.assign(n, 0);
        vis.assign(n, 0);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }
        dfs1(0);
        sol[0] = dp[0];
        fill(vis.begin(), vis.end(), 0);
        dfs2(0);
        return sol;
    }
};