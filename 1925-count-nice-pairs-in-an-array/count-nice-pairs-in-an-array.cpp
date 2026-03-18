class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) = nums[j] + rev(nums[i]);
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]);
        const int M = 1e9 + 7;
        int n = nums.size();
        map<int,int> m;
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            string temp = to_string(nums[i]);
            reverse(temp.begin(),temp.end());

            int x = stoi(temp);

            ans[i] = x;
        }

        for(int i = 0 ; i < n ; i++){
            nums[i] -= ans[i];
            m[nums[i]]++;
        }

        int ans1 = 0;
        for(auto it : m){
            ans1 = (ans1 + 1ll*it.second*1ll*(it.second-1)/2)%M;
        }

        return ans1 % M;
    }
};