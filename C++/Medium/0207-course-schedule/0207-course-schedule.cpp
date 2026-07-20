class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto it : prereq) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[temp]) {
                if (--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return cnt == n;
    }
};
