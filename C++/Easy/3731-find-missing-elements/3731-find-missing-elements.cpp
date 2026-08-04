class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_map<int, bool> mp;
        for(auto it : nums){
            mp[it] = true;
        }

        vector<int> sol;

        for(int i = mn + 1; i < mx; i++){
            if(!mp[i]){
                sol.push_back(i);
            }
        }

        return sol;
    }
};