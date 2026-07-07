class DSU{
    map<int, int> parent;
public:
    int find(int x){
        if(parent[x] == 0){
            parent[x] = x;
        }
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void merge(int x){
        for(int i = 2;i*i<=x;i++){
            if(x%i == 0){
                int par1 = find(i);
                int par2 = find(x/i);
                int par = find(x);
                parent[par1] = par;
                parent[par2] = par;
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int,int> mp;
        DSU dsu;
        int sol = 0;
        for(auto it : nums){
            dsu.merge(it);
        }
        for(auto it : nums){
            sol = max(sol,++mp[dsu.find(it)]);
        }
        return sol;
    }
};