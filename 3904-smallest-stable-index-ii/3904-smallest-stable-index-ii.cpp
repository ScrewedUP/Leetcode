class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n,0),suf(n,0);
        pre[0] = nums[0];
        suf[n-1] = nums.back();
        for(int i = 1 ; i < n ; i++){
            pre[i] = max(pre[i-1],nums[i]);
        }

        for(int i = n - 2 ; i >= 0 ; i--){
            suf[i] = min(suf[i+1],nums[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if ( pre[i] - suf[i] <= k ) return i;
        }

        return -1;
        
    }
};