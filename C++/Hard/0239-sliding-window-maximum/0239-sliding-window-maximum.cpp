class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<>> st;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            st.insert(nums[i]);
        }
        vector<int> sol = {*st.begin()};
        int low = 0, high = k;
        for(; high < n; high++, low++){
            st.erase(st.find(nums[low]));
            st.insert(nums[high]);
            sol.push_back(*st.begin()); 
        }
        return sol;
    }
};