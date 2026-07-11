class Solution {
public:
    void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited,int& vertices, int& totalEdges){
        visited[node] = true;
        vertices++;
        totalEdges += adj[node].size();
        for(int neighbour : adj[node]){
            if(visited[neighbour]){
                continue;
            }
            DFS(neighbour, adj, visited, vertices, totalEdges);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for(int node = 0; node < n; node++){
            if(visited[node]){
                continue;
            }
            int vertices = 0;
            int totalEdges = 0;
            DFS(node, adj, visited, vertices, totalEdges);
            totalEdges /= 2;
            if(totalEdges == (vertices * (vertices - 1)) / 2){
                completeComponents++;
            }
        }
        return completeComponents;
    }
};