class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> indices(n), position(n);

        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });

        for(int i = 0; i < n; i++){
            position[indices[i]] = i;
        }

        int LOG = 32 - __builtin_clz(n);

        vector<vector<int>> jump(n, vector<int>(LOG));

        int left = 0;

        for(int i = 0; i < n; i++){
            while(nums[indices[i]] - nums[indices[left]] > maxDiff){
                left++;
            }

            jump[i][0] = left;
        }
        for(int j = 1; j < LOG; j++){
            for(int i = 0; i < n; i++){
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }
        vector<int> answer;
        for(auto &query : queries){
            int x = position[query[0]];
            int y = position[query[1]];
            if(x > y){
                swap(x, y);
            }
            if(x == y){
                answer.push_back(0);
                continue;
            }
            int steps = 0;
            for(int j = LOG - 1; j >= 0; j--){
                if(jump[y][j] > x){
                    y = jump[y][j];
                    steps += (1 << j);
                }
            }
            if(jump[y][0] <= x){
                answer.push_back(steps + 1);
            }else{
                answer.push_back(-1);
            }
        }
        return answer;
    }
};