class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int> &n1,vector<int> &n2){
        if ( i >= n1.size() || j >= n2.size()) return 0;
        if ( t[i][j] != -1 ) return t[i][j];
        // skip from both i and j
        int skip1 = solve(i+1,j+1,n1,n2);

        //skip from i
        int skip2 = solve(i+1,j,n1,n2);

        //skip from j
        int skip3 = solve(i,j+1,n1,n2);

        int take = n1[i]*n2[j] + solve(i+1,j+1,n1,n2);

        return t[i][j] = max(skip1,max(skip2,max(skip3,take)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));
        int x = solve(0,0,nums1,nums2);
        if ( x == 0){
            int y = INT_MIN;
            for(int i = 0 ; i < nums1.size() ; i++){
                for(int j = 0 ; j < nums2.size() ; j++){
                    y = max(y,nums1[i]*nums2[j]);
                }
            }
            x = y;
        }
        return x;
    }
};