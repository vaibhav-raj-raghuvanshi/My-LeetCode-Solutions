class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        preSum = [0] * 1001
        for it in trips:
            preSum[it[1]] += it[0]
            preSum[it[2]] -= it[0]

        curr = 0
        
        for i in range (1001):
            curr += preSum[i]
            if(curr > capacity):
                return False
        
        return True