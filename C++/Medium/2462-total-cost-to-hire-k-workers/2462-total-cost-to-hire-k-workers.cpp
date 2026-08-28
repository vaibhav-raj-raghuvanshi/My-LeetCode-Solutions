class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<>> l, r;
        int low = 0;
        int high = n - 1;
        for(int i = 0; i < cand; i++){
            l.push(costs[low]);
            low++;
        }
        for(int i = 0; i < cand && low <= high; i++){
            r.push(costs[high]);
            high--;
        }
        long long int sol = 0;
        // 0 1 2 3 4 5 6 7 8 9
        while(k > 0){
            int n1 = INT_MAX, n2 = INT_MAX;
            if(!l.empty()){
                n1 = l.top();
            }
            if(!r.empty()){
                n2 = r.top();
            }
            if(n2 < n1){
                sol += n2;
                r.pop();
                if(low <= high){
                    r.push(costs[high--]);
                }
            }else{
                sol += n1;
                l.pop();
                if(low <= high){
                    l.push(costs[low++]);
                }
            }
            k--;
        }
        return sol;
    }
};