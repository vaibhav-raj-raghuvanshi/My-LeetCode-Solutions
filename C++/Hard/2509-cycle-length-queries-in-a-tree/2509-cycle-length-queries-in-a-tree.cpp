class Solution {
private:
    int logBase2(int x){
        return 31 - __builtin_clz(x);
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> numsSol;
        for(auto it : queries){
            int n1 = it[0], n2 = it[1];
            if(logBase2(n1) != logBase2(n2)){
                if(n1 < n2){
                    swap(n1,n2);
                }
            }
            int sol = 1;
            while(logBase2(n1) != logBase2(n2)){
                sol++;
                n1 /= 2;
            }
            while(n1 != n2){
                sol += 2;
                n1 /= 2;
                n2 /= 2;
            }
            numsSol.push_back(sol);
        }
        return numsSol;
    }
};