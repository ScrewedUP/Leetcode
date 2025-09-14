class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        vector<int> v;
        for(auto it : s){
            v.push_back(it);
        }
        sort(v.rbegin(),v.rend());
        vector<int> ans;
        int x = v.size();
        for(int i = 0 ; i < min(x,k) ; i++){
            ans.push_back(v[i]);
        }
        return ans;

    }
};