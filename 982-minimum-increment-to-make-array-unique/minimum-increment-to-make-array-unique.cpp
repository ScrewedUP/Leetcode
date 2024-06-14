class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v = nums;
        int cnt = 0;
        map<int,int> m;
        m[nums[0]]++;
        int ans = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if ( m.find(nums[i]) != m.end() ){
                nums[i] = nums[i-1] + 1;
            }
            m[nums[i]]++;
        }
        for(int i = 0 ; i < v.size() ; i++){
            ans += abs(v[i] - nums[i]);
        }
        return ans;
    }
};