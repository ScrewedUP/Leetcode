class Solution:
    def maxDepth(self, s: str) -> int:
        n = len(s)
        cnt = 0
        ans = 0
        for i in range(n):
            if s[i] == '(' : cnt+=1
            elif s[i] == ')' : cnt -= 1
            ans = max(ans,cnt)
        return ans