class Solution:
    def totalHammingDistance(self, nums: list[int]) -> int:
        total = 0
        n = len(nums)
        sol = [0] * (33)
        for it in nums:
            idx = 0
            while (it > 0):
                if it % 2 == 1:
                    sol[idx] += 1
                idx += 1
                it //= 2
        
        for it in sol:
            total += (it * (n - it))

        return total