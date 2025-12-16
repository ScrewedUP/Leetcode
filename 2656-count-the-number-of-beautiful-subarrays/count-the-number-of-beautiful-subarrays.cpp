class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int target = 0;
        map<int,int> m;
        m[0] = 1;
        int n = nums.size();
        long long x = 0;
        long long ans = 0;

        for(int i = 0 ; i < n ; i++){
            x ^= nums[i];
            int t = x^target;

            if ( m.find(t) != m.end()){
                ans += m[t];
            }

            m[t]++;
        }
        return ans;

    }
};