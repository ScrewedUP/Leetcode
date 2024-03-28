class Solution(object):
    
    def findKDistantIndices(self, nums, key, k):
        ans = []
        for i in range(len(nums)):
            for j in range(len(nums)):
                if abs(i-j) <= k and nums[j] == key:
                    ans.append(i)
                    break
        
        return ans
        