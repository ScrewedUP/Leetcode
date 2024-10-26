class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it : nums ) m[it]++;
        int cnt = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            int curr = nums[i];
            if ( m.find(curr) == m.end() ) continue;
            int req = k - nums[i];
            m[curr]--;
            if ( m[curr] == 0 ) m.erase(curr);
            bool ok = false;
            if ( m.find(req) != m.end() ){
                ok = true;
                m[req]--;
                if ( m[req] == 0 ) m.erase(req);
                cnt++;
            }
            if ( !ok ){
                m[curr]++;
            }
        }
        return cnt;
    }
};