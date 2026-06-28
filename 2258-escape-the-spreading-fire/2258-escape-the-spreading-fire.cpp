class Solution {
private:
    vector<vector<int>> fire;
    int n, m;
    void pushNeighbours(int i, int j, vector<vector<int>>& nums, queue<pair<int, int>>& q) {
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (int it = 0; it < 4; it++) {
            int ni = i + dx[it];
            int nj = j + dy[it];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && nums[ni][nj] == 0 &&
                fire[ni][nj] == INT_MAX) {
                fire[ni][nj] = fire[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    void pushNeighbours(int i, int j, int wt, vector<vector<bool>>& vis,queue<pair<pair<int, int>, int>>& q) {
        vis[i][j] = true;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (int it = 0; it < 4; it++) {
            int ni = i + dx[it];
            int nj = j + dy[it];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] &&
                fire[ni][nj] > wt + 1) {
                vis[ni][nj] = true;
                q.push({{ni, nj}, wt + 1});
            }
        }
    }

    bool isValid(int mid) {
        if (fire[0][0] <= mid)
            return false;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, mid});
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int wt = q.front().second;
            q.pop();
            if ((i == n - 2 && j == m - 1) || (j == m - 2 && i == n - 1)) {
                if (wt + 1 == fire[n - 1][m - 1]) {
                    return true;
                }
            }
            if (i == n - 1 && j == m - 1) {
                if (fire[i][j] >= wt)
                    return true;
            }
            pushNeighbours(i, j, wt, vis, q);
        }
        return false;
    }

public:
    int maximumMinutes(vector<vector<int>>& nums) {
        n = nums.size();
        m = nums[0].size();
        fire = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 1) {
                    q.push({i, j});
                    fire[i][j] = 0;
                } else if (nums[i][j] == 2) {
                    fire[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            pushNeighbours(i, j, nums, q);
        }

        int low = 0, high = min((int)1e9, fire[0][0]), sol = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                sol = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return sol;
    }
};