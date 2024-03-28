class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def go(n):
            if  n < 0 : return 0
            if n == 0 : return 1

            return go(n-1) + go(n-2)
        
        return go(n)