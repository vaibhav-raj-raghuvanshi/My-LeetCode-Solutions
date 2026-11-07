class Solution:
    def twoSum(self, nums1: list[int], target: int) -> list[int]:
        mp = {}
        nums = []
        for i in range (len(nums1)):
            nums.append((nums1[i], i))
        low = 0
        high = len(nums) - 1
        nums.sort()
        while low < high:
            if ((nums[low][0] + nums[high][0]) == target):
                return [nums[low][1], nums[high][1]]
            elif ((nums[low][0] + nums[high][0]) > target):
                high -= 1
            else :
                low += 1

        return [] 