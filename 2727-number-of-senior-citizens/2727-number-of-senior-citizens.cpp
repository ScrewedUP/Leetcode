class Solution {
public:
    int countSeniors(vector<string>& d) {
        int cnt = 0;
        for(int i = 0 ; i < d.size() ; i++){
            int num = 0;
            num += (d[i][11] - '0')*10;
            num += (d[i][12] - '0');
            if ( num > 60 ) cnt++;
        }
        return cnt;
    }
};