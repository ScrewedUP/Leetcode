class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        cnt = 0
        for i in range(n-1,-1,-1):
            if s[i] == ' ' and cnt == 0 : continue
            elif s[i] == ' ' : return cnt
            else : cnt += 1
        
        return cnt