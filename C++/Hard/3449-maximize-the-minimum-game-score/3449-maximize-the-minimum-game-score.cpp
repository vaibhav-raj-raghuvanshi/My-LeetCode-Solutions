class Solution {
private:
    bool isValid(long long int mid, vector<int> &nums, long long int m){
        vector<long long int> arr(nums.size(), 0);
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            arr[i] += nums[i];
            m--;
            if(m < 0){
                return false;
            }
            if(arr[i] < mid){
                long long int k = (mid - arr[i] + nums[i] - 1) / nums[i];
                if(m >= 2*k){
                    arr[i+1] += 1ll * nums[i+1] * k;
                }else{
                    return false;
                }
                m -= 2*k;
            }
        }
        if(m <= 0 && arr[n-1] < mid){
            return false;
        }
        arr[n-1] += nums[n-1];
        m--;
        if(arr[n-1] < mid){
            int k = (mid - arr[n - 1] + nums[n - 1] - 1) / nums[n - 1];
            return (m >= 2*k);
        }
        return true;
    }
public:
    long long maxScore(vector<int>& nums, int m) {
        long long int low = 0;
        long long int high = 1ll * *max_element(nums.begin(), nums.end()) * m;
        long long int sol = 0;
        while(low <= high){
            long long int mid = low + (high - low) / 2;
            if(isValid(mid, nums, m)){
                sol = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return sol;
    }
};