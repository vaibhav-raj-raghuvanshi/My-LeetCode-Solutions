class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        ctr = 0
        n = len(nums)
        sol = 0
        mp = {}
        mp[0] = -1
        for i in range (n):
            if(nums[i] == 1):
                ctr += 1
            else:
                ctr -= 1

            if ctr not in mp:
                mp[ctr] = i
            else:
                sol = max(sol, i - mp[ctr])
            
        return sol