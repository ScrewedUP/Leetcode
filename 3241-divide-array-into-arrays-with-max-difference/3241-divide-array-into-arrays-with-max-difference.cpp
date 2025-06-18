class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();        
        sort(nums.begin(),nums.end());
        int x = 0;
        vector<vector<int>> ans(n/3, vector<int>(3));
        for(int i = 0; i < n; i++){
            ans[x][i % 3] = nums[i];
            if ((i+1) % 3 == 0) x++;
        }
        for(int i = 0; i < ans.size(); i++){
            if (ans[i][2] - ans[i][0] > k) return {};
        }
        return ans;

    }
};