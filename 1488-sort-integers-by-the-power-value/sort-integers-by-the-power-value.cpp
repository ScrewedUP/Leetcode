class Solution {
public:
    int GetCount(int n){
        int cnt = 0;
        while ( n != 1 ){
            if ( n % 2 == 0 ){
                n/=2;
            }
            else n = 3*n + 1;
            cnt++;
        }
        return cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> vp;
        while ( lo <= hi ){
            int cnt = GetCount(lo);
            vp.push_back({cnt,lo});
            lo++;
        }
        sort(vp.begin(),vp.end());
        vector<int> ans;
        for(auto it : vp){
            ans.push_back(it.second);
        }
        return ans[k-1];
    }
};