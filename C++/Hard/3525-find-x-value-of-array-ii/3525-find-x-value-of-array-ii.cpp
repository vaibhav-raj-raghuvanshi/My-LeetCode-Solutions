struct Node {
    vector<int> freq;
    int prod;
    bool empty;

    Node() : freq(5, 0), prod(0), empty(true) {};
};

class SegTree {
    int size;
    vector<Node> st;
    int k;

    void build (vector<int>& nums, int l, int r, int v) {
        if (l == r) {
            st[v].freq[nums[l] % k] += 1;
            st[v].prod = nums[l] % k;
            st[v].empty = false;
            return;
        }
        int m = (l + r) / 2;
        build(nums, l, m, v*2);
        build(nums, m+1, r, v*2+1);
        for (int i = 0; i < k; i++) {
            st[v].freq[i] += st[v*2].freq[i];
        }
        long long t = st[v*2].prod;
        for (int i = 0; i < k; i++) {
            st[v].freq[(t*i)%k] += st[v*2+1].freq[i];
        }
        st[v].prod = (st[v*2].prod*st[v*2+1].prod)%k;
        st[v].empty = false;
    }

    void update(int pos, int val, int l, int r, int v) {
        if (l == r) {
            fill(st[v].freq.begin(), st[v].freq.end(), 0);
            st[v].freq[val % k] += 1;
            st[v].prod = val % k;
            st[v].empty = false;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(pos, val, l, m, v*2);
        } else {
            update(pos, val, m+1, r, v*2+1);
        }
        fill(st[v].freq.begin(), st[v].freq.end(), 0);
        for (int i = 0; i < k; i++) {
            st[v].freq[i] += st[v*2].freq[i];
        }
        long long t = st[v*2].prod;
        for (int i = 0; i < k; i++) {
            st[v].freq[(t*i)%k] += st[v*2+1].freq[i];
        }
        st[v].prod = (st[v*2].prod*st[v*2+1].prod)%k;
        st[v].empty = false;
    }

    Node ask(int l, int r, int tl, int tr, int v, int x) {
        if (l > tr || tl > r) return Node();
        if (l == tl && r == tr) {
            return st[v];
        }
        int m = (tl + tr) / 2;
        Node a = ask(l, min(m, r), tl, m, v*2, x);
        Node b = ask(max(m+1, l), r, m+1, tr, v*2+1, x);
        if (a.empty) return b;
        if (b.empty) return a;
        Node ans;
        ans.empty = false;
        long long t = a.prod;
        for (int i = 0; i < k; i++) {
            ans.freq[i] += a.freq[i];
        }
        for (int i = 0; i < k; i++) {
            ans.freq[(t*i)%k] += b.freq[i];
        }
        ans.prod = (a.prod*b.prod)%k;
        return ans;
    }
public:

    SegTree(vector<int>& nums, int key) {
        size = nums.size();
        st.resize(4*size+1);
        k = key;
        build(nums, 0, size-1, 1);
    }

    void change(int pos, int val) {
        update(pos, val, 0, size - 1, 1);
    }

    int query(int l, int r, int x) {
        Node ans = ask(l, r, 0, size - 1, 1, x);
        return ans.freq[x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % k;
        }
        vector<int> ans;
        SegTree st{nums, k};
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];
            int val = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];
            st.change(idx, val);
            int cnt = st.query(start, n-1, x);
            ans.push_back(cnt);
        }
        return ans;
    }
};