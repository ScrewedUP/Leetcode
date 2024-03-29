class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        maxi = max(nums)
        print(maxi)
        tot = n*(n+1)//2
        cnt = 0
        i = 0
        j = 0
        while j < n :
            if nums[j] == maxi :
                cnt += 1
            while cnt >= k :
                if nums[i] == maxi:
                    cnt-=1
                i+=1

            tot -= j - i + 1
            j+=1
        return tot
        