class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ctrd = 1
        ctri = 1
        sol = 1
        for i in range (1, len(nums)):
            if(nums[i] == nums[i-1]):
                ctri = 1
                ctrd = 1
            elif (nums[i] > nums[i-1]):
                ctri += 1
                ctrd = 1
            else:
                ctrd += 1
                ctri = 1
            sol = max({sol, ctri, ctrd})
        return sol