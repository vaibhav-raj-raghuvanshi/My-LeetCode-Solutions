class Solution {
private:
    bool nex(vector<int> &sol, int n, int m, vector<vector<char>> & nums, vector<vector<bool>> &vis){
        vis[sol[0]][sol[1]] = true;
        int ni = sol[0], nj = sol[1];
        if(nums[ni][nj] == 'R'){
            nj++;
        }else if(nums[ni][nj] == 'L'){
            nj--;
        }else if(nums[ni][nj] == 'U'){
            ni--;
        }else{
            ni++;
        }
        if(ni >= n || nj >= m || ni < 0 || nj < 0 || vis[ni][nj]){
            return false;
        }
        sol = {ni, nj};
        return true;
    }
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> sol = {0, 0};
        while(nex(sol, n, m, grid, vis));
        return sol;
    }
};