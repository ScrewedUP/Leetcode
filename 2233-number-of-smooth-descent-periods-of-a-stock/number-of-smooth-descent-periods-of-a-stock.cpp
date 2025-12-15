class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int l = 0;
        int n = p.size();
        long long cnt = 1;
        for(int i = 1 ; i < n ; i++){
            if ( p[i] != p[i-1] - 1){
                l = i;
            }
            cnt += i - l + 1;
            
        }
        return cnt;
    }
};