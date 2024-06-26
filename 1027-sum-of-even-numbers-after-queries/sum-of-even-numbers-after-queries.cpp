class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto it : nums){
            if ( it % 2 == 0){
                sum += it;
            }
        }
        vector<int> ans;
        for(auto it : queries){
            int val = it[0];
            int idx = it[1];
            int v = nums[idx];
            if ( v % 2 == 0 && val % 2 == 0){
                sum += val;
                nums[idx] += val;
            }
            else if ( v % 2 == 0 && val % 2 != 0){
                sum -= v;
                nums[idx] += val;
            }
            else if ( v % 2 != 0 && val % 2 == 0){
                nums[idx] += val;
            }
            else{
                nums[idx] += val;
                sum += nums[idx];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};