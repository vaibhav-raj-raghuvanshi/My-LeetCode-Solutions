class Solution {
private:
    void dfs(int node, vector<bool> &visited, vector<vector<pair<int, int>>> &adj, int cap){
        visited[node] = true;
        for(auto it : adj[node]){
            if(it.second > cap && !visited[it.first]){
                dfs(it.first, visited, adj, cap);
            }
        }
    }
    bool isValid(int mid, int k, vector<vector<pair<int, int>>> &adj){
        int n = adj.size();
        vector<bool> visited(n, false);
        int ctr = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, adj, mid);
                if(++ctr >= k){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 1;
        int sol = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
            high = max(high, it[2]);
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(mid, k, adj)){
                sol = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return sol;
    }
};