class Solution:
    def maxDepth(self, s: str) -> int:
        cnt = 0
        ans = 0
        for i in s:
            if i == '(' : cnt+=1
            elif i == ')' : cnt -= 1
            ans = max(ans,cnt)
        return ans