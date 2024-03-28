class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0 : return 0
        newNum = set(nums)
        ans = 1
        for it in newNum:
            if (it-1) not in newNum:
                cnt = 1
                while (it+cnt) in newNum:
                    cnt += 1
                ans = max(ans,cnt)
        
        return ans