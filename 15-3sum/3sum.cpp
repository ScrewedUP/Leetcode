class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<tuple<int,int,int>,int> m;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int target = -curr;

            int j = i + 1;
            int k = n - 1;

            while ( j < k ){
                int x = nums[j] + nums[k];
                if ( x == target && m.find(make_tuple(nums[i],nums[j],nums[k])) == m.end()){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    m[make_tuple(nums[i],nums[j],nums[k])]++;
                    
                }
                else if ( x > target ) k--;
                else j++;
            }
        }
        return ans;
    }
};