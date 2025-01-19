class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = LLONG_MAX;
        long long x = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            x += abs(brr[i] - arr[i]);
        }
        ans = min(ans,x);
        long long y = k;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i = 0 ; i < arr.size() ; i++){
            y += abs(brr[i] - arr[i]);
        }
        ans = min(ans,y);
        return ans;
    }
};