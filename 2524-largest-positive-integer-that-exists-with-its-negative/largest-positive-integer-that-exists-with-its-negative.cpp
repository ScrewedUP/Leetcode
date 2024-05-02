class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        for(auto it: nums){
            if ( it > 0){
                if ( m.find(-1*it) != m.end()){
                    ans = max(ans,it);
                }
            }
        }
        return ans;
    }
};