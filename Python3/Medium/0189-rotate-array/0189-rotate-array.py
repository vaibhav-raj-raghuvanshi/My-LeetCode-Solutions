class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        temp = []
        ptr = len(nums) - k
        n = len(nums)
        for i in range (len(nums)):
            temp.append(nums[(ptr % n)])
            ptr += 1
        for i in range (len(nums)):
            nums[i] = temp[i]