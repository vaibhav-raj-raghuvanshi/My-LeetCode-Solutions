class NumMatrix {
private:
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>>& mat) {
        nums = mat;
        int n = nums.size(), m = nums[0].size();
        for(int i = 0;i < n; i++){
            for(int j = 1; j < m; j++){
                nums[i][j] += nums[i][j-1];
            }
        }
        for(int i = 1;i < n; i++){
            for(int j = 0; j < m; j++){
                nums[i][j] += nums[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int tSum = nums[row2][col2];
        int cSum = 0;
        if((row1 - 1) >= 0 && (col1 - 1) >= 0){
            cSum = nums[row1 - 1][col1 - 1];
        }
        int lSum = 0;
        if((col1 - 1) >= 0){
            lSum = nums[row2][col1 - 1];
        }
        int uSum = 0;
        if((row1 - 1) >= 0){
            uSum = nums[row1 - 1][col2];
        }
        return tSum - lSum - uSum + cSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */