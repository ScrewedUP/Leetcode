class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()

        # either last three
        # first two and last

        lastThree = nums[-1]*nums[-2]*nums[-3]

        firstTwoAndLast = nums[0]*nums[1]*nums[-1]

        return max(lastThree,firstTwoAndLast)