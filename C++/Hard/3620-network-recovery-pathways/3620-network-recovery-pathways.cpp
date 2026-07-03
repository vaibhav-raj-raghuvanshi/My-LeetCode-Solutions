class Solution {
private:
    int n;
    vector<vector<pair<int, int>>> adj;
    bool isValid(int mid, long long k, vector<bool> &online){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq; // total cost, node
        pq.push({0, 0});
        vector<long long> visited(n, 1e15);
        while(!pq.empty()){
            long long curr = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            if(node == n-1){
                return true;
            }
            if(visited[node] < curr){
                continue;
            }
            for(auto it : adj[node]){
                long long newVal = curr + it.second;
                if((it.second >= mid) && (online[it.first]) && (newVal <= k) && (visited[it.first] > newVal)){
                    visited[it.first] = newVal;
                    pq.push({newVal, it.first});
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        adj = vector<vector<pair<int, int>>>(n); // node, value
        int low = INT_MAX;
        int high = INT_MIN;
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            low = min(low, it[2]);
            high = max(high, it[2]);
        }
        int sol = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isValid(mid, k, online)){
                sol = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return sol;
    }
};