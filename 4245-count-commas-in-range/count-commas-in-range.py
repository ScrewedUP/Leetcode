class Solution:
    def countCommas(self, n: int) -> int:
        ans = 0
        def getDig(i):
            cnt = 0
            while i > 0:
                cnt+=1
                i//=10
            return cnt
    
        for i in range(1,n+1):
            x = getDig(i)
            if x > 3:
                ans += 1
        
        return ans