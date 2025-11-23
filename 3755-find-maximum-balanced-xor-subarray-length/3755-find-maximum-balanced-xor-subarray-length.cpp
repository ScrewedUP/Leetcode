class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int> m;
        m[{0,0}] = -1;
        int n = nums.size();
        vector<int> pre(n,0);
        int x = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            x ^= nums[i];
            pre[i] = ( i > 0 ? pre[i-1] : 0) + (nums[i] % 2 == 0 ? 1 : -1);

            if ( m.find({x,pre[i]}) != m.end()){
                ans = max(ans,i - m[{x,pre[i]}]);
            }
            else{
                m[{x,pre[i]}] = i;
            }
        }
        return ans;
    }
};