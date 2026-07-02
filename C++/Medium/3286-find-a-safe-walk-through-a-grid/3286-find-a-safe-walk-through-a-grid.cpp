class Solution {
private:
    priority_queue<vector<int>> pq;
    vector<int> di = {0,-1,0,1};
    vector<int> dj = {1,0,-1,0};
    vector<vector<int>> visited;
    int n, m;
    void pushNeighbor(int i, int j, int health, vector<vector<int>>& nums){
        for(int k = 0;k < 4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m){
                if(nums[ni][nj] == 0 && visited[ni][nj] < health){
                    pq.push({health, ni, nj});
                    visited[ni][nj] = health;
                }else if(nums[ni][nj] == 1 && (visited[ni][nj] < (health - 1))){
                    pq.push({health - 1, ni, nj});
                    visited[ni][nj] = health - 1;
                }
            }
        }
    }
public:
    bool findSafeWalk(vector<vector<int>>& nums, int health) {
        n = nums.size();
        m = nums[0].size();
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        if(nums[0][0]){
            health--;
        }
        visited[0][0] = health;
        pq.push({health, 0, 0});
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int tempHealth = temp[0];
            int i = temp[1];
            int j = temp[2];
            pushNeighbor(i, j, tempHealth, nums);
            if(visited[n-1][m-1] > 0){
                return true;
            }
        }
        return false;
    }
};