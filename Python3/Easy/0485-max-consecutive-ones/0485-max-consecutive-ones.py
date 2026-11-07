class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        sol = 0
        temp = 0
        for i in range (len(nums)):
            if nums[i] == 1 :
                temp += 1
                sol = max(sol, temp)
            else :
                temp = 0
        return sol