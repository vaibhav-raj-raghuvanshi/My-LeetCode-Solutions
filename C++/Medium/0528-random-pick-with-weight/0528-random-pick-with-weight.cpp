class Solution {
private:
    vector<long long int> nums;
public:
    Solution(vector<int>& w) {
        long long int prev = 0;
        for(auto it : w){
            prev += it;
            nums.push_back(prev);
        }
    }
    
    int pickIndex() {
        int r = rand() % nums.back();
        return upper_bound(nums.begin(), nums.end(), r) - nums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */