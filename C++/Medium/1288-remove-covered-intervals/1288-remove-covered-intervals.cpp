class Solution {
private:
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.first != p2.first){
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int sol = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, bool(*)(pair<int, int>, pair<int, int>)> pq(compare);
        for(auto it : intervals){
            pq.push({it[0], it[1]});
        }
        pair<int, int> temp = pq.top();
        pq.pop();
        while(!pq.empty()){
            if(pq.top().second > temp.second){
                temp = pq.top();
                sol++;
            }
            pq.pop();
        }
        return sol;
    }
};