class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        M = 1000000007
        @cache
        def go(idx,g1,g2):
            if idx >= len(nums):
                if g1 == g2 and g1 is not 0:
                    return 1
                return 0
            
            skip = go(idx+1,g1,g2)
            x = 0
            y = 0
            if g1 == 0:
                x = nums[idx]
            else:
                x = gcd(nums[idx],g1)

            if g2 == 0:
                y = nums[idx]
            else:
                y = gcd(nums[idx],g2)
            take1 = go(idx+1,x,g2)
            take2 = go(idx+1,g1,y)

            return (skip+take1+take2)%M

        return go(0,0,0)