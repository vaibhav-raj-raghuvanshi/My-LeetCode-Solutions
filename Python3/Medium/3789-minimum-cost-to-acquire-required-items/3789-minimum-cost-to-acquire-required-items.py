class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        w1 = cost1 * need1 + cost2 * need2
        w2 = max(need1, need2) * costBoth
        w3 = min(need1, need2) * costBoth + (need1 - min(need1, need2)) * cost1 + (need2 - min(need1, need2)) * cost2
        return min({w1, w2, w3})