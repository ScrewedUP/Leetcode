class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        sort(nums.begin(),nums.end());
        unordered_map<long long,long long> m;
        int o = 0;
        for(auto it : nums){
            if ( it == 1 ) o++;
            m[it]++;
        }
        if ( o > 1){
            ans = max(ans,o);
        }
        for(int i = 0 ; i < nums.size(); i++){
            if ( nums[i] == 1 ) continue;
            long long curr = nums[i];
            int cnt = 1;
            while ( curr < 1e5){
                curr = curr*curr;
                if ( m.find(curr) != m.end()){
                    cout << curr << " " << sqrt(curr);
                    cnt++;
                }
                else break;
            }
            if ( cnt >= 2){
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};