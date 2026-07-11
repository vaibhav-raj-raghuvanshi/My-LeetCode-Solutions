class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> sol(queries.size(), -1);
        vector<vector<int>> newQ;
        for(int i = 0;i<queries.size();i++){
            auto it = queries[i];
            int x = min(it[1], it[0]);
            int y = max(it[1], it[0]);
            if(x == y || nums[y] > nums[x]){
                sol[i] = y;
            }else{
                newQ.push_back({y, nums[x], i});
            }
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // value, queryIndex
        int itr = 0;
        sort(newQ.begin(), newQ.end());
        for(int i = 0; i<nums.size();i++){
            while(!pq.empty() && pq.top()[0] < nums[i]){
                sol[pq.top()[1]] = i;
                pq.pop();
            }
            while(itr < newQ.size() && newQ[itr][0] == i){
                pq.push({newQ[itr][1], newQ[itr][2]});
                itr++;
            }
        }
        return sol;
    }
};
// entire solution by me <3
// yt pe sab segment tree ya BS use kar rahe
