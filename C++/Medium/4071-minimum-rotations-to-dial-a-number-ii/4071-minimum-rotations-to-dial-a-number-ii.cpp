class Solution {
public:
    int minRotations(int n, string s) {
        int last = s[n-1] - '0';
        vector<vector<int>> soln = {
            {0,1,2,3,4,5,4,3,2,1},
            {1,0,1,2,3,4,5,4,3,2},
            {2,1,0,1,2,3,4,5,4,3},
            {3,2,1,0,1,2,3,4,5,4},
            {4,3,2,1,0,1,2,3,4,5},
            {5,4,3,2,1,0,1,2,3,4},
            {4,5,4,3,2,1,0,1,2,3},
            {3,4,5,4,3,2,1,0,1,2},
            {2,3,4,5,4,3,2,1,0,1},
            {1,2,3,4,5,4,3,2,1,0}
        };
        int prev = 0;
        int sol = 0;
        int mx = 0;

        for(auto it : s){
            int curr = it - '0';
            sol += soln[prev][curr];
            mx = min(mx, (soln[prev][last] - soln[prev][curr]));
            prev = curr;
        }
        return sol + mx;
    }
};