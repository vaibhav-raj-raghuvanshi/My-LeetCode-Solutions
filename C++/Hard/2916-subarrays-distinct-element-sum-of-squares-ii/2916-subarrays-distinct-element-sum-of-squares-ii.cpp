class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    vector<long long> SqSumSeg;
    vector<long long> SumSeg;
    vector<long long> lazyTree;
    void lazyAdd(int i, int l, int r, int val){
        int length = r - l + 1;
        SqSumSeg[i] += 2*val*SumSeg[i] + length * val * val;
        SumSeg[i] += length * val;
    }
    void updateRange(int st, int e, int i, int l, int r, int val){
        if(lazyTree[i] != 0){
            lazyAdd(i, l, r, lazyTree[i]);
            if(l != r){
                lazyTree[2*i + 1] += lazyTree[i];
                lazyTree[2*i + 2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }
        if(l > e || r < st ){
            return;
        }
        if(l >= st && r <= e){
            lazyAdd(i, l, r, val);
            if(l != r){
                lazyTree[2*i + 1] += val;
                lazyTree[2*i + 2] += val;
            }
            return;
        }
        int mid = (l + r)/2;
        updateRange(st, e, 2*i+1, l, mid, val);
        updateRange(st, e, 2*i+2, mid+1, r, val); 
        SumSeg[i] = SumSeg[2*i + 1] + SumSeg[2*i + 2];
        SqSumSeg[i] = SqSumSeg[2*i + 1] + SqSumSeg[2*i + 2];
    }
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        SqSumSeg.assign(4*n, 0);
        SumSeg.assign(4*n, 0);
        lazyTree.assign(4*n, 0);
        vector<int> pastSeenIdx(100001, -1);
        long long result = 0;
        for(int i = 0; i < n; i++){
            int start = pastSeenIdx[nums[i]] + 1;
            int end = i;
            updateRange(start, end, 0, 0, n-1, 1);
            result = (result + SqSumSeg[0] ) % mod;
            pastSeenIdx[nums[i]] = i;
        }
        return result;

    }
};