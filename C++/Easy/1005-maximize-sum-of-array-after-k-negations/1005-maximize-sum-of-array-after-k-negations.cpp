class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        long long int sol = accumulate(nums.begin(), nums.end(), 0ll);
        for(auto it : nums){
            pq.push(it);
        }
        while(k > 0 && pq.top() <= 0){
            int temp = pq.top();
            pq.pop();
            pq.push(-temp);
            sol -=(2 * (temp));
            k--; 
        }
        if(k % 2 == 0){
            return sol;
        }
        return sol - 2 * pq.top();
    }
};