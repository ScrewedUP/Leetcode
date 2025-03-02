class Solution {
public:
    int t[2001][2001][4];
    int solve(int idx,int k,int m,int x,vector<int> &v){
        if ( k == 0 ) return 0;
        if ( idx >= v.size()){
            if ( k == 0 ){
                return 0;
            }
            else return -1e9;
        }
        if ( t[idx][k][m] != -1 ) return t[idx][k][m];
        long long op1 = -10000007;
        if ( m >= x){
            op1 = solve(idx+1,k,x,x,v);    
        }
        else if ( m == 0 ){
            op1 = solve(idx+1,k-1,x,x,v);   
        }
        long long op2 = v[idx] + solve(idx+1,k,max(0,m-1),x,v);
        long long op3 = -10000007;
        if ( m == 0 || m == 1){
            op3 = v[idx] + solve(idx+1,k-1,x,x,v);    
        }
        return t[idx][k][m] = max(op1,max(op2,op3));
        
    }
    int maxSum(vector<int>& nums, int k, int m) {
        memset(t,-1,sizeof t);
        return solve(0,k,m,m,nums);
    }
};