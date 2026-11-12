class Solution:
    def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        nums.append(k + 1)
        low = 0
        high = 0
        n = len(nums)
        sol = 0
        curr = 1
        while(high < n):
            if(nums[high] >= k):
                cnt = high - low
                sol += (cnt * (cnt + 1) // 2)
                low = high + 1
                curr = 1
                high += 1
                continue

            while(nums[high] * curr >= k):
                sol += (high - low)
                curr /= nums[low]
                low += 1
            
            curr *= nums[high]
            high += 1
        
        return sol
        