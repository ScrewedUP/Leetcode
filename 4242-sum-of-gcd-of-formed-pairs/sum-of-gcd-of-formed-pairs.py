class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefixGcd = []
        mx = -1

        for i in range(0,len(nums)):
            mx = max(mx,nums[i])
            prefixGcd.append(gcd(nums[i],mx))
        
        prefixGcd.sort()
        ans = 0
        i = 0
        j = len(nums) - 1
        while i < j:
            ans += gcd(prefixGcd[i],prefixGcd[j])
            i+=1
            j-=1
        
        return ans
