class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,vector<int> &v){
        if ( j == v.size() ) return v[i];
        if ( j == v.size() - 1 ) return max(v[i],v[j]);
        if ( t[i][j] != -1 ) return t[i][j];
        int x = max(v[i],v[j]) + solve(j+1,j+2,v);
        int y = max(v[i],v[j+1]) + solve(j,j+2,v);
        int z = max(v[j],v[j+1]) + solve(i,j+2,v);

        return t[i][j] = min(x,min(y,z));
    }
    int minCost(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,1,nums);
    }
};