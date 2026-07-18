class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unsigned int n = nums.size();
        if(n <= 2){
            return n;
        }
        return 1 << bit_width(n);
    }
};
