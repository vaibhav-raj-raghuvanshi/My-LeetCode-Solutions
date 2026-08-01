class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int> mp;
        for(char ch : word){
            mp[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        int i = 1;
        int sol = 0;
        while(i <= 4 && !pq.empty()){
            int j = 8;
            while(!pq.empty() && j > 0){
                j--;
                sol += pq.top().first * i;
                pq.pop();
            }
            i++;
        }
        return sol;
    }
};