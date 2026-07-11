class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> minHeap;
        priority_queue<int> pq;
        int n = profits.size();
        for(int i = 0;i<n;i++){
            minHeap.push({capital[i], profits[i]});
        }
        while(k--){
            while(!minHeap.empty() && minHeap.top().first <= w){
                pq.push(minHeap.top().second);
                minHeap.pop();
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};