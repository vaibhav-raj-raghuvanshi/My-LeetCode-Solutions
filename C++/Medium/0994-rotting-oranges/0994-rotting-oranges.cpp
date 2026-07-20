class Solution {
private:
    int fresh,n,m;
    queue<vector<int>>q;
    vector<vector<bool>> visited;
    void pushNeighbors(vector<int> &temp,vector<vector<int>> &grid){
        int x = temp[0],y = temp[1],curr = temp[2];
        vector<int> iDiff = {-1,0,1,0};
        vector<int> jDiff = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int newI = x + iDiff[i];
            int newJ = y + jDiff[i];
            if(newI >= 0 &&  newJ>= 0 && newI < n && newJ < m && grid[newI][newJ] == 1 && !visited[newI][newJ]){
                q.push({newI,newJ,curr+1});
                fresh--;
                visited[newI][newJ] = true;
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        fresh = 0;
        n = grid.size();
        m = grid[0].size();
        visited = vector<vector<bool>> (n,vector<bool>(m,false));
        for(int  i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int cnt = 0;
        while(!q.empty()){
            vector<int> temp = q.front();
            cnt = max(cnt,temp[2]);
            q.pop();
            pushNeighbors(temp,grid);
            if(fresh == 0){
                return cnt + 1;
            }
        }
        return -1;
    }
};