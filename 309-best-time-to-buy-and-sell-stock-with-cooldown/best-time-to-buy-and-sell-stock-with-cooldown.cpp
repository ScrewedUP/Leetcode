class Solution {
public:
    int t[5002][3];
    int solve(int i , int w,vector<int> &prices){
        if ( i >= prices.size()) return 0;
        if ( t[i][w] != -1 ) return t[i][w];
        int buy = INT_MIN;
        int sell = INT_MIN;
        int skip = solve(i+1,w,prices);
        if ( w == 0){
            buy = -1*prices[i] + solve(i+1,1,prices);
        }
        else{
            sell = prices[i] + solve(i+2,0,prices);
        }
        return t[i][w] = max({buy,sell,skip});

    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(0,0,prices);
    }
};