class segmentTree{
private:
    int n;
    vector<int> tree;
public:
    segmentTree(vector<int> &nums){
        n = nums.size();
        tree.resize(4*n, 0);
        build(0, n-1, 0, nums);
    }

    void build(int low, int high, int node, vector<int> &nums){
        if(low == high){
            tree[node] = nums[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(low, mid, node*2 + 1, nums);
        build(mid + 1, high, node*2 + 2, nums);
        tree[node] = tree[node*2 + 1] + tree[node*2 + 2];
    }
    
    void update(int idx, int val){
        updateUtil(0, n-1, idx, val, 0);
    }

    void updateUtil(int low, int high, int idx, int val, int node){
        if(idx < low || idx > high){
            return;
        }
        if(low == high){
            tree[node] = val;
            return;
        }
        int mid = low + (high - low)/ 2;
        if(idx <= mid){
            updateUtil(low, mid, idx, val, node * 2 + 1);
        }else{
            updateUtil(mid + 1, high, idx, val, node * 2 + 2);
        }
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    int query(int low, int high){
        return queryUtil(low, high, 0, n-1, 0);
    }

    int queryUtil(int low, int high, int start, int end, int node){
        // no overLapping
        if(low > end || high < start){
            return 0;
        }
        // complete overLapping
        if(low <= start && high >= end){
            return tree[node];
        }
        // partial overLapping
        int mid = start + (end - start) / 2;
        return queryUtil(low, high, start, mid, node * 2 + 1) + queryUtil(low, high, mid + 1, end, node * 2 + 2);
    }
};

class NumArray {
private:
    segmentTree* node;
public:
    NumArray(vector<int>& nums) {
        node = new segmentTree(nums);
    }
    
    void update(int index, int val) {
        node -> update(index, val);
    }
    
    int sumRange(int left, int right) {
        return node -> query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */