class Solution {
private:
    int m, n;

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> nums(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums[i][j] = matrix[i][j] - '0';
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j])
                    nums[i][j] += nums[i - 1][j];
            }
        }
        vector<vector<int>> left(n, vector<int>(m, -1));
        vector<vector<int>> right(n, vector<int>(m, m));
        for (int i = 0; i < n; i++) {
            stack<pair<int, int>> st;
            for (int j = 0; j < m; j++) {
                while (!st.empty() && st.top().first > nums[i][j]) {
                    right[i][st.top().second] = j;
                    st.pop();
                }
                st.push({nums[i][j], j});
            }
            while (!st.empty()) {
                st.pop();
            }
            for (int j = m - 1; j >= 0; j--) {
                while (!st.empty() && st.top().first > nums[i][j]) {
                    left[i][st.top().second] = j;
                    st.pop();
                }
                st.push({nums[i][j], j});
            }
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sol = max(sol, nums[i][j] * (right[i][j] - left[i][j] - 1));
            }
        }
        return sol;
    }
};