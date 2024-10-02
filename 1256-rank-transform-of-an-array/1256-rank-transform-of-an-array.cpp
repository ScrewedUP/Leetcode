class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<pair<int,int>> vp(n);
        for(int i = 0 ; i < n ; i++){
            vp[i] = {arr[i],i};
        }
        sort(vp.begin(),vp.end());
        int rank = 1;
        for(int i = 0 ; i < n ; i++){
            if ( i == 0 ){
                ans[vp[i].second] = rank;
            }
            else{
                if ( vp[i].first == vp[i-1].first){
                    ans[vp[i].second] = rank;
                }
                else{
                    rank++;
                    ans[vp[i].second] = rank;
                }
            }
        }
        return ans;
    }
};