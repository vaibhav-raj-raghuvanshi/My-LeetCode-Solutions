class Solution:
    def totalHammingDistance(self, nums: list[int]) -> int:
        total = 0
        n = len(nums)
        for i in range(32):
            count = sum((num >> i) & 1 for num in nums)
            total += count * (n - count)
        return total