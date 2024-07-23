class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        for(auto it : nums) m[it]++;
        vector<int> ans;
        vector<pair<int,int>> vp;
        for(auto it : m){
            vp.push_back({it.second,it.first});
        }
        sort(vp.begin(),vp.end(),[](pair<int,int> &a,pair<int,int> &b){
            if ( a.first == b.first){
                return a.second > b.second;
            }
            else return a.first < b.first;
        });
        for(int i = 0 ; i < vp.size() ; i++){
            for(int j = 0 ; j < vp[i].first ; j++){
                ans.push_back(vp[i].second);
            }
        }
        return ans;
    }
};