class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> vp;
        for(int i = 0 ; i < n ; i++){
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end());
        vector<int> maxi(n);
        maxi[0] = vp[0].second;
        for (int i = 1; i < n; i++) {
            maxi[i] = max(maxi[i-1],vp[i].second);
        }
        int ans = 0;
        for(int i = 0 ; i < worker.size() ; i++){
            int idx = upper_bound(vp.begin(), vp.end(), make_pair(worker[i], INT_MAX), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.first < b.first;
                }) - vp.begin() - 1;
            if (idx >= 0) {
                ans += maxi[idx];
            }
        }
        return ans;


    }
};