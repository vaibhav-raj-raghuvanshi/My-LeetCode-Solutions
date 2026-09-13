class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int sol = 0;
        for(int di = -(n - 1); di <= n - 1; di++){
            for(int dj = -(n - 1); dj <= n - 1; dj++){
                int curr = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int x = i + di;
                        int y = j + dj;
                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(img1[x][y] == 1 && img2[i][j] == 1){
                                curr++;
                            }
                        }
                    }
                }
                sol = max(sol, curr);
            }
        }
        return sol;
    }
};