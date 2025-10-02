class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        int curr = 0;
        int cnt = 0;
        for(int i = 0 ; i < m.size() ; i++){
            if ( m[i][0] > curr ){
                cnt += m[i][0] - curr - 1;
                
            }
            curr = max(curr,m[i][1]);
        }
        if ( curr < days){
            cnt += days - curr;
        }
        return cnt;
        
    }
};