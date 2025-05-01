class Solution {
public:
    // [40,33,31,26,21]
    // [33,31,21,14]
    // [33,31,7]
    // [7,2]
    // [5]
    int t[31][6000];
    int solve(int i,int ans,vector<int> &v){
        if ( i == v.size()){
            if ( ans >= 0 ) return ans;
            else return INT_MAX;
        }
        if ( t[i][ans + 3000] != -1 ) return t[i][ans + 3000];
        int x = solve(i+1,ans + v[i],v);
        int y = solve(i+1,ans - v[i],v);

        return t[i][ans+ 3000] = min(x,y);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(t,-1,sizeof(t));
        return solve(0,0,stones);
    }
};