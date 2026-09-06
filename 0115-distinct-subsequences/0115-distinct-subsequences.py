class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        N = len(s)
        M = len(t)

        @cache
        def go(i,j):
            if j == M:
                return 1
            
            if i == N:
                return 0

            take = 0
            skip = 0
            if s[i] == t[j]:
                take = go(i+1,j+1)
            
            skip = go(i+1,j)

            return take + skip
        
        return go(0,0)