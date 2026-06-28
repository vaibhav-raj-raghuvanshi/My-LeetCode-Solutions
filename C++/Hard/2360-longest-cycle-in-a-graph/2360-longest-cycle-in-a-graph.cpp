#define vi vector<int>
class Solution {
private:
    vi visited, pathVisited, depth;
    int n, sol;
    void dfs(int i ,vector<vi> &adj, int curr){
        visited[i] = 1;
        pathVisited[i] = 1;
        depth[i] = curr;
        for(auto it : adj[i]){
            if(!visited[it]){
                dfs(it, adj, curr + 1);
            }else if(pathVisited[it]){
                sol = max(sol, curr - depth[it] + 1);
            }else{
                continue;
            }
        }
        pathVisited[i] = 0;
        return;
    }
public:
    int longestCycle(vector<int>& edges) {
        sol = -1;
        n = edges.size();
        depth = vi(n,0);
        visited = vi(n,0);
        pathVisited = vi(n,0);
        vector<vi> adj(n);
        for(int i = 0;i<n;i++){
            if(edges[i] != -1){
                adj[i].push_back(edges[i]);
            }
        }
        for(int i= 0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, 0);
            }
        }
        return sol;
    }
};