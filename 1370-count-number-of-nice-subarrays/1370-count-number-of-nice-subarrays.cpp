class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        int x = 0;
        map<int,int> m;
        m[0] = 1;
        for(int r = 0 ; r < nums.size() ; r++){
            x += nums[r] % 2;
            int req = x - k;
            if ( m.find(req) != m.end()){
                cnt = cnt + m[req];
            }
            m[x]++;
        }
        return cnt;
    }
};