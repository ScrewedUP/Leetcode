class Solution {
public:
    int t[5002][3];
    int maxProfit(vector<int>& prices) {
        memset(t,0,sizeof(t));
        int n = prices.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int w = 0 ; w <= 1 ; w++){
                if ( w == 0){
                    t[i][w] = max(t[i+1][w] , -1*prices[i] + t[i+1][1]);
                }
                else{
                    t[i][w] = max(t[i+1][w] , prices[i] + t[i+2][0]);
                }
            }
        }
        return t[0][0];
    }
};