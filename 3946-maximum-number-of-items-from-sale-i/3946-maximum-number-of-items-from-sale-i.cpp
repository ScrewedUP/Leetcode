class Solution {
public:
    int dp[1001][1501][2];
    int solve(int i,int total,vector<vector<int>> &items,int bud,vector<int> &facCount,int taken){
        if ( i >= items.size()) return 0;

        if ( dp[i][total][taken] != -1 ) return dp[i][total][taken];

        int skip = solve(i+1,total,items,bud,facCount,0);

        int take = 0;

        if ( items[i][1] + total <= bud ){
            take = 1 + (taken ? 0 : facCount[i]) + max(solve(i,items[i][1] + total,items,bud,facCount,1),solve(i+1,items[i][1] + total,items,bud,facCount,0));
        }

        return dp[i][total][taken] = max(skip,take);
    }
    /*
        factor[i] divides factor[j] ==> factor[j] % factor[i] == 0
    */
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        memset(dp,-1,sizeof(dp));
        int n = items.size();
        vector<int> facCount(n,0);
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < n ; j++){
                if ( i != j && items[j][0] % items[i][0] == 0) cnt++;
            }
            facCount[i] = cnt;
        }
        return solve(0,0,items,budget,facCount,0);
    }
};