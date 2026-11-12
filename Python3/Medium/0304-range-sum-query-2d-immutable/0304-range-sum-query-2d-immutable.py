class NumMatrix:
    nums = [[]]
    def __init__(self, matrix: list[list[int]]):
        self.nums = matrix
        n = len(self.nums)
        m = len(self.nums[0])
        for i in range (n):
            for j in range (1, m):
                self.nums[i][j] += self.nums[i][j-1]
        
        for i in range (1, n):
            for j in range (m):
                self.nums[i][j] += self.nums[i-1][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        tSum = self.nums[row2][col2]
        cSum = 0
        if((row1 - 1) >= 0 and (col1 - 1) >= 0):
            cSum = self.nums[row1 - 1][col1 - 1]
        lSum = 0
        if((col1 - 1) >= 0):
            lSum = self.nums[row2][col1 - 1]
        uSum = 0
        if((row1 - 1) >= 0):
            uSum = self.nums[row1 - 1][col2]
        return tSum - lSum - uSum + cSum


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)