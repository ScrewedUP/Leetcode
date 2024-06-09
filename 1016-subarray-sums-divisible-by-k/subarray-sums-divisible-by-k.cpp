class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            int req = (sum)%k;
            if ( req < 0 ) req += k;
            if ( m.find(req) != m.end()) ans += m[req];
            m[req]++;
        }
        return ans;
    }
};