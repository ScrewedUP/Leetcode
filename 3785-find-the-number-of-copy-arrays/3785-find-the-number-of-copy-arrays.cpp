class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int L = b[0][0];
        int R = b[0][1];
        for(int i = 1 ; i < o.size() ; i++){
            int D = o[i] - o[i-1];
            L = max(L + D,b[i][0]);
            R = min(R + D,b[i][1]);
        }
        if ( L > R) return 0;
        else return R-L+1;
    }
};