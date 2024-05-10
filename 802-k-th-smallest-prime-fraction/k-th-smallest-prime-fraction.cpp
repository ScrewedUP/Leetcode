class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>> v;
        for(int i = 0 ; i < arr.size();i++){
            for(int j = i+1; j < arr.size(); j++){
                float ans = (float)arr[i]/(float)arr[j];
                v.push_back({ans,{i,j}});

            }
        }
        sort(v.begin(),v.end());
        auto ans = v[k-1];
        return {arr[ans.second.first],arr[ans.second.second]};
        
    }
};