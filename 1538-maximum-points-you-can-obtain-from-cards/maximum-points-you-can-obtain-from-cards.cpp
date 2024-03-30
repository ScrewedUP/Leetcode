class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sum  = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += cp[i];
        }
        if ( n == k ) return sum;
        int toRemove = n - k;
        vector<int> prefix(n);
        prefix[0] = cp[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = cp[i] + prefix[i-1];
        }
        int i = 0 ;
        int j = n - k - 1;
        while ( j < n ){
            int currentWindowSum = 0;
            if ( i == 0 ){
                currentWindowSum = prefix[j];
            }
            else{
                currentWindowSum = prefix[j] - prefix[i-1];
            }
            ans = max(ans,sum - currentWindowSum);
            // cout << ans << ":" << currentWindowSum << endl;
            j++;i++;
        }
        return ans;
    }
};