class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        N = len(arr)
        pre = [0]*N
        pre[0] = arr[0]

        for i in range(1,N):
            pre[i] = pre[i-1]^arr[i]

        sz = len(queries)
        print(pre)
        ans = [0]*sz
        for i,(l,r) in enumerate(queries):
            if l > 0:
                ans[i] = pre[r]^pre[l-1]
            else:
                ans[i] = pre[r]
        
        return ans
        