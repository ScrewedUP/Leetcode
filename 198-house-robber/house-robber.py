class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        @cache
        def go(idx):
            if idx >= n :
                return 0
            take = nums[idx] + go(idx+2)
            notTake = go(idx+1)
            return max(take,notTake)
        
        return go(0)