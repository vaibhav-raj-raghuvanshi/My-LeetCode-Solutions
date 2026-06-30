#define ll long long
#define vi vector<int>
#define vll vector<ll>
class SegmentTree {
private:
    vector<pair<ll, ll>> tree;
    pair<ll, ll> merge(pair<ll, ll> left, pair<ll, ll> right){
        return {
            min(left.first, right.first),
            max(left.second, right.second)
        };
    }
public:
    SegmentTree(int n){
        tree.resize(4 * n);
    }
    void build(int node, int start, int end, vi &nums){
        if(start == end){
            tree[node] = {nums[start], nums[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    pair<ll, ll> query(int node, int start, int end, int left, int right){
        if(end < left || start > right){
            return {LLONG_MAX, LLONG_MIN};
        }
        if(start >= left && end <= right){
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        pair<ll, ll> leftAns = query(2 * node + 1, start, mid, left, right);
        pair<ll, ll> rightAns = query(2 * node + 2, mid + 1, end, left, right);
        return merge(leftAns, rightAns);
    }
};
class Solution {
public:
    ll maxTotalValue(vi &nums, int k) {
        int n = nums.size();
        SegmentTree st(n);
        st.build(0, 0, n - 1, nums);
        priority_queue<tuple<ll, int, int>> pq;
        set<pair<int, int>> visited;
        pair<ll, ll> curr = st.query(0, 0, n - 1, 0, n - 1);
        pq.push({curr.second - curr.first, 0, n - 1});
        visited.insert({0, n - 1});
        ll ans = 0;
        while(!pq.empty() && k){
            auto [val, left, right] = pq.top();
            pq.pop();
            ans += val;
            k--;
            if(left == right){
                continue;
            }
            if(!visited.count({left + 1, right})){
                visited.insert({left + 1, right});
                pair<ll, ll> temp = st.query(0, 0, n - 1, left + 1, right);
                pq.push({temp.second - temp.first, left + 1, right});
            }
            if(!visited.count({left, right - 1})){
                visited.insert({left, right - 1});
                pair<ll, ll> temp = st.query(0, 0, n - 1, left, right - 1);
                pq.push({temp.second - temp.first, left, right - 1});
            }
        }
        return ans;
    }
};