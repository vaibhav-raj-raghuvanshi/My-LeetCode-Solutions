class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        curr = float(sum(nums[:k]))
        sol = curr / k
        for i in range(k, len(nums)):
            curr = curr - nums[i - k] + nums[i]
            sol = max(sol, curr / k)
        return sol