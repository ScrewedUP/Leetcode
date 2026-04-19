class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            int target = sum - k;

            if ( m.find(target) != m.end()){
                ans += m[target];
            }
            m[sum]++;
        }
        return ans;
    }
};