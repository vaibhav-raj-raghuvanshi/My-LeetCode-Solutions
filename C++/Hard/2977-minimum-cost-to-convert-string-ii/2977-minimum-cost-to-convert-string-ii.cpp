#define ll long long
class Solution {
private:
    const ll INF = LLONG_MAX/2;
public:
    ll minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        int m = cost.size();
        unordered_map<string, unordered_map<string, ll>> dist;
        unordered_set<string> nodes;
        unordered_set<int> lengths;
        for(int i = 0; i < m; i++){
            string from = original[i];
            string to = changed[i];
            nodes.insert(from);
            nodes.insert(to);
            lengths.insert(from.size());
            if(!dist[from].count(to)){
                dist[from][to] = cost[i];
            }
            else{
                dist[from][to] = min(dist[from][to], (ll)cost[i]);
            }
        }
        for(auto &via : nodes){
            for(auto &from : nodes){
                if(!dist.count(from) || !dist[from].count(via)){
                    continue;
                }
                for(auto &to : nodes){
                    if(!dist.count(via) || !dist[via].count(to)){
                        continue;
                    }
                    if(!dist[from].count(to)){
                        dist[from][to] = INF;
                    }
                    dist[from][to] = min(
                        dist[from][to],
                        dist[from][via] + dist[via][to]
                    );
                }
            }
        }
        vector<ll> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == INF){
                continue;
            }
            if(source[i] == target[i]){
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            for(auto len : lengths){
                if(i + len > n){
                    continue;
                }
                string from = source.substr(i, len);
                string to = target.substr(i, len);
                if(!dist.count(from) || !dist[from].count(to)){
                    continue;
                }
                dp[i + len] = min(
                    dp[i + len],
                    dp[i] + dist[from][to]
                );
            }
        }
        if(dp[n] == INF){
            return -1;
        }
        return dp[n];
    }
};