class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for(auto it: nums){
            mp[it]++;
        }
        vector<int> sol;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        while(k > 0){
            sol.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return sol;
    }
};