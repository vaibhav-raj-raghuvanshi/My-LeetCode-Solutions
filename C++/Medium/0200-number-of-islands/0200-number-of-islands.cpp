class Solution {
private:
    int n, m;
    void pushNeighbours(int i, int j, vector<vector<char>>& grid,
                        vector<vector<bool>>& vis, queue<pair<int, int>>& q) {
        vis[i][j] = true;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (int it = 0; it < 4; it++) {
            if ((i + dx[it]) < n && (i + dx[it]) >= 0 && (j + dy[it]) < m &&
                (j + dy[it]) >= 0 && !vis[i + dx[it]][j + dy[it]] &&
                grid[(i + dx[it])][(j + dy[it])] == '1') {
                vis[i + dx[it]][j + dy[it]] = true;
                q.push({i + dx[it], j + dy[it]});
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sol = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    sol++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        pushNeighbours(it.first, it.second, grid, vis, q);
                    }
                }
            }
        }
        return sol;
    }
};