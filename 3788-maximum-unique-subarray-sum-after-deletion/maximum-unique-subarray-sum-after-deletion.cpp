class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int ans = 0;
        int cnt = 0;
        for(auto it : nums){
            if ( it >= 0 && s.find(it) == s.end()){
                ans += it;
                cnt++;
                s.insert(it);
            }
        }
        if ( cnt == 0){
            return *max_element(nums.begin(),nums.end());
        }
        return ans;
    }
};