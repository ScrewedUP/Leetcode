class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> v;
        for(int i = 0 ; i < arr.size() ; i++){
            int x = __builtin_popcount(arr[i]);
            v.push_back({x,arr[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it : v){
            ans.push_back(it.second);
        }
        return ans;
    }
};