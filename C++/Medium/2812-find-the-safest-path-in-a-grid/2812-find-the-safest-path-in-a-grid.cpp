#define vi vector<int>
class Solution {
    vector<vi> visited;
    int n;
    vi di = {0, -1, 0, +1};
    vi dj = {+1, 0, -1, 0};
    queue<vi> q;
    void pushNeighbor(int i, int j, int mid, int vis, vector<vi> &nums){
        for(int k = 0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];

            if(ni<0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj] == vis || nums[ni][nj] < mid){
                continue;
            }

            visited[ni][nj] = vis;
            q.push({ni, nj});
        }
    }

public:
    int maximumSafenessFactor(vector<vi>& nums) {
        n = nums.size();
        visited = vector<vi> (n, vi(n, 0));
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(nums[i][j]){
                    visited[i][j] = true;
                    nums[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        
        while(!q.empty()){
            vi temp = q.front();
            q.pop();
            for(int k = 0;k<4;k++){
                int ni = temp[0] + di[k];
                int nj = temp[1] + dj[k];

                if(ni<0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj]){
                    continue;
                }

                visited[ni][nj] = 1;
                nums[ni][nj] = temp[2] +  1;
                q.push({ni, nj, nums[ni][nj]});
            }
        }
        
        int low = 0;
        int high = min(nums[0][0], nums[n-1][n-1]);
        int vis = n + 1;
        int sol = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            bool flag = false;
            vis++;
            visited[0][0] = vis;
            if(nums[0][0] >= mid){
                q.push({0, 0});
            }
            while(!q.empty()){
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                if(i == n-1 && j == n-1){
                    flag = true;
                    while(!q.empty()){
                        q.pop();
                    }
                    break;
                }
                pushNeighbor(i, j, mid, vis, nums);
            }
            if(flag){
                low = mid + 1;
                sol = mid;
            }else{
                high = mid - 1;
            }
        }
        return sol;
    }
};