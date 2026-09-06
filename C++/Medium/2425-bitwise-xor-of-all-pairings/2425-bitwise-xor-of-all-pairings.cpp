class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(((n1%2) == 0) && ((n2%2) == 0)){
            return 0;
        }
        int sol = 0;
        if(n1 % 2 == 0){
            for(auto it : nums1){
                sol ^= it;
            }
            return sol;
        }
        if(n2 % 2 == 0){
            for(auto it : nums2){
                sol ^= it;
            }
            return sol;
        }
        for(auto it : nums1){
            sol ^= it;
        }
        for(auto it : nums2){
            sol ^= it;
        }
        return sol;
    }
};