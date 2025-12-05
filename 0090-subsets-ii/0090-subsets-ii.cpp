class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0 ; i < ( 1 << n) ; i++){
            vector<int> temp;
            for(int j = 0 ; j < n ; j++){
                if ( i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        vector<vector<int>> ans2(ans.begin(),ans.end());
        return ans2;
    }
};