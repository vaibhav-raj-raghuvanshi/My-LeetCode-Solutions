class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long int w1 = 1ll * cost1 * need1 + 1ll * cost2 * need2;
        long long int w2 = 1ll * max(need1, need2) * costBoth;
        long long int w3 = 1ll * min(need1, need2) * costBoth + 1ll * (need1 - min(need1, need2)) * cost1 + 1ll *(need2 - min(need1, need2)) * cost2;
        return min({w1, w2, w3});
    }
};