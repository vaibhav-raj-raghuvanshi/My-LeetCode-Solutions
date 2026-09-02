class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        // O((k+n)*(log n))
        for(auto &it : nums){
            pq.push(it);
        }
        // n log n
        while(k > 1){
            k--;
            pq.pop();
        }
        // k log n
        return pq.top();
    }
};