class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> vp;
        for(int i = 0  ; i < nums.size() ; i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.rbegin(),vp.rend());
        vector<pair<int,int>> vp1;
        for(int i = 0 ; i < k ; i++){
            vp1.push_back({vp[i].second,vp[i].first});
        }
        sort(vp1.begin(),vp1.end());
        vector<int> ans;
        for(int i = 0 ; i < k ; i++){
            ans.push_back(vp1[i].second);
        }
        return ans;
    }
};