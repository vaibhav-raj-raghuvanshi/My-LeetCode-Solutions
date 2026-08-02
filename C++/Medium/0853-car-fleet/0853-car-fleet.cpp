class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> nums;
        for(int i = 0;i <n; i++){
            nums.push_back({target - position[i], speed[i]}); // dist, speed
        }
        int sol = 1;
        sort(nums.begin(), nums.end());
        double prev =  nums[0].first*1.0/nums[0].second;
        for(int i = 1;i < n; i++){
            if(prev < nums[i].first*1.0/nums[i].second){
                sol++;
                prev = nums[i].first*1.0/nums[i].second;
            }
        }
        return sol;
    }
};