# Optimal O(n + q) Solution + General DSU Approach

# Two Approaches | Component Labeling (Optimal) & DSU (General)

## Approach 1: Assign Component Numbers (Optimal)

### Intuition

Since `nums` is already sorted, every adjacent pair whose difference exceeds `maxDiff` forms a **barrier** that cannot be crossed. Therefore, the array is naturally divided into connected components.

Instead of using a DSU, we can directly assign each index a **component number**. Whenever we encounter a barrier, we increment the component number. Two indices can reach each other if and only if they belong to the same component.

### Approach

1. Initialize the first element as component `0`.
2. Traverse the array from left to right.
3. If `nums[i] - nums[i-1] > maxDiff`, increment the component number.
4. Assign the current component number to index `i`.
5. For every query, simply check whether both indices have the same component number.

### Complexity

- **Time complexity:** $$O(n + q)$$

- **Space complexity:** $$O(n)$$

### Code

```cpp
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int compNo = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                compNo++;
            }
            component[i] = compNo;
        }
        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(component[it[0]] == component[it[1]]);
        }

        return sol;
    }
};
```

---

## Approach 2: DSU + Sorting *(Works even if the array were unsorted)*

### Intuition

If the array were **not sorted**, the previous observation could no longer be applied directly. Instead, we first sort the elements by their values. Any valid path between two values must pass through consecutive values in sorted order.

Thus, we only need to connect adjacent elements in the sorted order whenever their difference is at most `maxDiff`. After constructing these connected components using DSU, each query reduces to checking whether both indices belong to the same component.

### Approach

1. Store every element along with its original index.
2. Sort the elements by value (here a priority queue is used to process them in sorted order).
3. Traverse consecutive elements in sorted order.
4. If the difference between two consecutive values is at most `maxDiff`, merge their original indices in the DSU.
5. For every query, simply check whether both indices have the same DSU parent.

### Complexity

- **Time complexity:** $$O(n \log n + q\alpha(n))$$

- **Space complexity:** $$O(n)$$

### Code

```cpp
class DSU{
    vector<int> parent;

public:
    DSU(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int parX = find(x);
        int parY = find(y);

        parent[parX] = parY;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        DSU dsu(n);

        pair<int, int> temp = pq.top();

        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            pq.pop();

            if(abs(temp.first - curr.first) <= maxDiff){
                dsu.merge(temp.second, curr.second);
            }

            temp = curr;
        }

        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(dsu.find(it[0]) == dsu.find(it[1]));
        }

        return sol;
    }
};
```

---

### Comparison

| Approach | Time Complexity | Space Complexity | Works for Unsorted Array? |
|:---------|:---------------:|:----------------:|:-------------------------:|
| Component Labeling | **O(n + q)** | O(n) | ❌ |
| DSU + Sorting | **O(n log n + qα(n))** | O(n) | ✅ |

---

**By:** **vaibhav_jpd** == **rosvert** ❤️

🌐 **Portfolio:** https://vaibhavrajsingh.in

Thank Youuuu...<3