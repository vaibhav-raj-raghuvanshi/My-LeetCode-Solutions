class Solution {
private:
    int cnt(vector<int> &nums, int k){
        int p = 0;
        int n = nums.size();
        vector<int> pre;
        int s = 0;
        vector<int> suff;
        for(int i = 0;i < n;i++){
            if(i != k){
                pre.push_back(gcd(p, nums[i]));
                p = gcd(p, nums[i]);
            }
            if(n-i-1 != k){
                suff.push_back(gcd(s, nums[n-i-1]));
                s = gcd(s, nums[n-1-i]);
            }
        }
        reverse(suff.begin(), suff.end());
        int sol = 0;
        for(int i = 0; i < pre.size(); i++){
            if(pre[i] == suff[i]){
                sol++;
            }
        }
        return sol-1;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        set<int> canBe;
        canBe.insert(-1);
        canBe.insert(0);
        canBe.insert(n-1);
        int pre = nums[0];
        for(int i = 1;i<n-1;i++){
            int temp = gcd(pre, nums[i]);
            if(pre != temp){
                canBe.insert(i);
                pre = temp;
            }
        }
        int suff = nums[n-1];
        for(int i = n-2; i>=0; i--){
            int temp = gcd(suff, nums[i]);
            if(suff != temp){
                canBe.insert(i);
                suff = temp;
            }
        }
        int sol = 0;
        for(auto it : canBe){
            sol = max(sol, cnt(nums, it));
        }
        return sol;
    }
};