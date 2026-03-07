class Solution {
public:
    const int M = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        // 2*x , x , 2*x
        map<int,vector<int>> m;
        long long ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            int c = nums[i];
            if ( m.find(2*c) == m.end() || m[2*c].size() < 2 ){
                continue;
            }
            // cout << i << " ";
            // index of the jsut greater

            /* a1 , a2 , a3 ,a4 , a5
                        i
            */    
            int sz = m[2*c].size();
            // int x = upper_bound(m[2*c].begin(),m[2*c].end(),i) - m[2*c].begin();
            // cout << i << " ";
            int pos = upper_bound(m[2*c].begin(), m[2*c].end(), i) - m[2*c].begin();

            long long right = m[2*c].size() - pos;

            long long left = lower_bound(m[2*c].begin(), m[2*c].end(), i) - m[2*c].begin();
            ans += (left%M*right%M)%M;       
        }
        return ans%M;
    }
};