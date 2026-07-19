class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t1 = 0, t2 = 0;
        for (auto it : nums) {
            t1 ^= (it & ~t2);
            t2 ^= (it & ~t1);
        }
        return t1;
    }
};