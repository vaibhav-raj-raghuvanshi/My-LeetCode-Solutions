#define vi vector<int>
#define vii vector<vi>
class Solution {
private:
    int sol;
    void bfs(int node, int n, vii &adj){
        queue<pair<int,int>> q;
        vi visited(n, -1);
        visited[node] = 0;
        q.push({node,-1});
        while(!q.empty()){
            auto [curr,parent] = q.front();
            q.pop();
            for(auto next : adj[curr]){
                if(visited[next] == -1){
                    visited[next] = visited[curr] + 1;
                    q.push({next,curr});
                }else if(next != parent){
                    sol = min(sol, (visited[curr] + visited[next] + 1));
                }
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vii adj(n);
        sol = INT_MAX;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<n;i++){
            bfs(i, n, adj);
        }
        if(sol == INT_MAX){
            return -1;
        }
        return sol;
    }
};