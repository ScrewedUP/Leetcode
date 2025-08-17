class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> v1(n);
        vector<long long> v2(n);
        v2[0] = prices[0];
        for(int i = 1 ; i < n ; i++){
            v2[i] = v2[i-1] + prices[i];
        }
        v1[0] = prices[0]*strategy[0];
        for(int i = 1 ; i < n ; i++){
            v1[i] = v1[i-1] + (prices[i]*strategy[i]);
        }
        long long ans = v1.back();
        long long temp = ans;
        for(int i = 0 ; i < n ; i++){
            long long curr = (i > 0 ? v1[i-1] : 0);
            int j = i+(k/2)-1;
            int t = j + (k/2);
            if ( j >= 0 && t < n){
                curr += v2[t] - v2[j];
                curr += v1.back() - v1[t];
                ans = max(ans,curr);
            }   
        }
        return ans;
    }
};