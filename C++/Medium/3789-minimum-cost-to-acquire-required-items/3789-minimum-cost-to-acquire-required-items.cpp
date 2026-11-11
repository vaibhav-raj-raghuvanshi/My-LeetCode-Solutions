class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, long long int need1, long long int need2) {
        long long int w1 = cost1 * need1 + cost2 * need2;
        long long int w2 = max(need1, need2) * costBoth;
        long long int w3 = min(need1, need2) * costBoth + (need1 - min(need1, need2)) * cost1 + (need2 - min(need1, need2)) * cost2;
        return min({w1, w2, w3});
    }
};