class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        long long ans = m;
        sort(a.begin(),a.end());
        for(int i = 0 ; i < a.size() ; i++){
            if ( ans >= a[i]){
                ans += a[i];
            }
            else return false;
        }
        return true;
    }
};