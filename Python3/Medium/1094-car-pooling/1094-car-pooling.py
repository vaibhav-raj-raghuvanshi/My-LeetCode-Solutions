class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        preSum = [0] * 1001
        for it in trips:
            preSum[it[1]] += it[0]
            preSum[it[2]] -= it[0]

        if(preSum[0] > capacity):
            return False

        for i in range (1001):
            preSum[i] += preSum[i-1]
            if(preSum[i] > capacity):
                return False
        
        return True