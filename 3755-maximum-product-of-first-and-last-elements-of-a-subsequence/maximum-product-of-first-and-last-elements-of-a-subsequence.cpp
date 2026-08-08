class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> gp(n,INT_MIN);
        vector<long long> gn(n,INT_MAX);

        
            gp[n-1] = nums.back();
    
        
            gn[n-1] = nums.back();
        

        for(int i = n - 2 ; i >= 0 ; i--){
            gp[i] = max(gp[i+1],1LL*nums[i]);
            gn[i] = min(gn[i+1],1LL*nums[i]);
        }

        long long ans = LLONG_MIN;

        for(int i = 0 ; i < n ; i++){
            if ( i + m - 1 < n){
                if ( nums[i] < 0){
                    long long curr = nums[i]*gn[i+m-1];
                    ans = max(ans,curr);
                }
                else{
                    long long curr = nums[i]*gp[i+m-1];
                    ans = max(ans,curr);
                }
            }
            else break;
        }
        return ans;

    }
};