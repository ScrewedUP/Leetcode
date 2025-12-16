class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0] = 1;
        int n = nums.size();
        long long x = 0;
        long long ans = 0;

        for(int i = 0 ; i < n ; i++){
            x ^= nums[i];
            if ( m.find(x) != m.end()){
                ans += m[x];
            }

            m[x]++;
        }
        return ans;

    }
};