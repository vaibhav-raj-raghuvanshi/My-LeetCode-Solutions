#define ll long long
class Solution {
private:
    vector<vector<ll>> dist;
    void fw(int n){
        for (int via = 0; via < n; via++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        dist = vector<vector<ll>>(n,vector<ll>(n,INT_MAX));
        for(auto it : edges){
            dist[it[0]][it[1]] = min((ll)it[2], dist[it[0]][it[1]]);
            dist[it[1]][it[0]] = min((ll)it[2], dist[it[1]][it[0]]);
        }
        for(int i = 0;i <n ;i++){
            dist[i][i] = 0;
        }
        fw(n);
        pair<int, int> sol = {-1, INT_MAX};
        for(int i = 0;i < n;i++){
            int temp = 0;
            for(int j = 0;j<n;j++){
                if(dist[i][j] <= dt){
                    if(++temp > sol.second){
                        break;
                    }
                }
            }
            if(temp <= sol.second){
                sol = {i, temp};
            }
        }
        return sol.first;
    }
};