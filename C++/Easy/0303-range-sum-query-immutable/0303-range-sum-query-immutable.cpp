class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& arr) {
        nums = {0};
        for(int i = 0; i < arr.size(); i++){
            nums.push_back(nums[i] + arr[i]);
            cout << nums.back() << " ";
        }
    }
    int sumRange(int left, int right) {
        return nums[right + 1] - nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */