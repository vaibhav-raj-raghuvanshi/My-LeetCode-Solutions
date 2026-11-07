class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}
        for i in range (len(nums)):
            comp = target - nums[i]
            if comp in mp:
                return [mp[comp], i]
            mp[nums[i]] = i
        return []