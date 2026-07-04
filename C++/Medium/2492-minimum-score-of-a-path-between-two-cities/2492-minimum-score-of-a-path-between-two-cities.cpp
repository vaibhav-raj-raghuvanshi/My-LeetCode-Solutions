class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int sol = INT_MAX;
        vector<bool> visited(n+1, false);
        visited[0] = true;
        visited[1] = true;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it.first]){
                    q.push(it.first);
                    visited[it.first] = true;
                }
                sol = min(sol, it.second);
            }
        }
        return sol;
    }
};