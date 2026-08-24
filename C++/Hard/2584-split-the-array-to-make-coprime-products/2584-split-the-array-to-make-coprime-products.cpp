class Solution {
private:
    vector<int> spd;
    map<int, int> lastIndexOf;
    void init(){
        for(int i = 0;i <= 1000000; i++){
            spd.push_back(i);
        }
        for(int i = 2;i <= 1000000;i++){
            if(spd[i] == i){
                int j = 2 * i;
                while(j <= 1000000){
                    spd[j] = i;
                    j += i;
                }
            }
        }
    }
    void setFactors(int n, int idx, unordered_map<int, int> &mp){
        while(n > 1){
            mp[spd[n]] = idx;
            n /= spd[n];
        }
    }
    void setPtr(int n, int &ptr, unordered_map<int, int> &mp){
        while(n > 1){
            ptr = max(ptr, mp[spd[n]]);
            n /= spd[n];
        }
    }
public:
    int findValidSplit(vector<int>& nums) {
        init();
        int ptr = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i< n ;i++){
            setFactors(nums[i], i, mp);
        }
        for(int i = 0;i < n - 1;i++){
            setPtr(nums[i], ptr, mp);
            if(ptr == i){
                return ptr;
            }
        }
        return -1;
    }
};