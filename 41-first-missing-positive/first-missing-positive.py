class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        curr = 1
        for i in range(n):
            if nums[i] <= 0 : continue
            elif nums[i] == curr : curr += 1
            elif nums[i] > curr : break
        return curr