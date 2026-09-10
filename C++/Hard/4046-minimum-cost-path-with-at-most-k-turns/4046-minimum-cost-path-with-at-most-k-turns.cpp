class Solution {
private:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // cost, k, i, j, dir
    int maxK, m, n;
    void pushNeighbor(int cost, int k, int i, int j, int dir, vector<vector<int>> &nums, vector<vector<vector<vector<int>>>> &maxCost){
        vector<int> di = {-1,+0,+1,+0};
        vector<int> dj = {+0,+1,+0,-1};
        for(int idx = 0; idx < 4; idx++){
            if((idx + 2) % 4 != dir){
                int newK = k;
                if(idx != dir){
                    newK++;
                }
                int ni = i + di[idx];
                int nj = j + dj[idx];
                if(ni < n && nj < m && ni >= 0 && nj >= 0 && newK <= maxK){
                    int nCost = cost + nums[ni][nj];
                    if(nCost < maxCost[ni][nj][newK][idx]){
                        maxCost[ni][nj][newK][idx] = nCost;
                        pq.push({nCost, newK, ni, nj, idx});
                    }
                }
            }
        }
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        maxK = k;
        n = grid.size();
        m = grid[0].size();
        // cost[i][j][newK][idx]
        vector<vector<vector<vector<int>>>> maxCost(n, vector<vector<vector<int>>>(m, vector<vector<int>>(k+1, vector<int>(4, (int)1e9))));
        // up, right, down, left
        pq.push({grid[0][0], 0, 0, 0, 1});
        pq.push({grid[0][0], 0, 0, 0, 2});
        while(!pq.empty()){
            vector<int> node = pq.top();
            pq.pop();
            // cost, k, i, j, dir
            if(node[2] == n-1 && node[3] == m-1){
                return node[0];
            }
            pushNeighbor(node[0], node[1], node[2], node[3], node[4], grid, maxCost);
        }
        return -1;
    }
};