class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       unordered_map<long long,vector<long long>> m;
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        int M = 1e9 + 7;
        for(int i = 0 ; i < nums.size() ; i++){
            long long x = nums[i];
            long long idx = i;
            long long req = 2*x;
            const auto& cnt = m[req];
            if ( cnt.size() > 0 ){
                long long l = lower_bound(cnt.begin(),cnt.end(),idx) - cnt.begin();
                long long r = cnt.end() - upper_bound(cnt.begin(),cnt.end(),idx);
                long long tot = l*r;
                ans = ( ans + tot)%M;
            }
        }
        return (int)ans;
    }
};