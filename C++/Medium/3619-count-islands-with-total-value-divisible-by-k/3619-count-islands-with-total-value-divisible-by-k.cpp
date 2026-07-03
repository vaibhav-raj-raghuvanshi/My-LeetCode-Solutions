class Solution {
private:
    int m,n;
    int dfs(int i, int j, vector<vector<int>>& nums, int k){
        if(i < 0 || i >= n || j < 0 || j >= m || nums[i][j] == 0){
            return 0;
        }
        int curr = nums[i][j];
        nums[i][j] = 0;
        return (curr + dfs(i+1,j,nums,k)+ dfs(i,j+1,nums,k)+ dfs(i,j-1,nums,k)+ dfs(i-1,j,nums,k)) % k;
    }
public:
    int countIslands(vector<vector<int>>& nums, int k) {
        n = nums.size();
        m = nums[0].size();
        int sol = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(nums[i][j]){
                    if(dfs(i, j, nums, k) == 0){
                        sol++;
                    }
                }
            }
        }
        return sol;
    }
};