class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [float(inf)] * (n + 1)
        dp[0] = 0
        for i in range (1, len(costs) + 1):
            if i >= 1:
                dp[i] = min(dp[i], dp[i-1] + 1)
            if i >= 2:
                dp[i] = min(dp[i], dp[i-2] + 4)
            if i >= 3:
                dp[i] = min(dp[i], dp[i-3] + 9)
            dp[i] += costs[i-1]
        return dp[n]