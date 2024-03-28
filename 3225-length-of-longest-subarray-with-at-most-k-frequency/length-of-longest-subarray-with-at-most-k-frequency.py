class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 0
        left = 0
        m = collections.Counter()
        for right in range(len(nums)):
            m[nums[right]] += 1
            while m[nums[right]] > k:
                m[nums[left]] -= 1
                left += 1
            ans = max(ans,right - left + 1)
        
        return ans