class DSU{
    vector<int> parent;
public:
    DSU(int n){
        for(int i = 0;i<n;i++){
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

        if(parX == parY){
            return;
        }
        if(parX > parY){
            swap(parX, parY);
        }

        parent[parY] = parX;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);
        for(auto it : pairs){
            dsu.merge(it[0], it[1]);
        }
        unordered_map<int,priority_queue<char, vector<char>, greater<>>> mp;
        for(int i = 0;i<n;i++){
            mp[dsu.find(i)].push(s[i]);
        }
        string sol = "";
        for(int i = 0;i<n;i++){
            sol.push_back(mp[dsu.find(i)].top());
            mp[dsu.find(i)].pop();
        }
        return sol;
    }
};