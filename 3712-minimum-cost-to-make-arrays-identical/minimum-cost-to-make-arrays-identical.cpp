class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        if ( arr == brr ) return 0;
        /*
            -7  5  9
            -5 -2  7

            2   7  2
        */

        long long ans = k;
        long long ans1 = 0;
        for(int i = 0 ;i  < arr.size() ; i++){
            ans1 += abs(arr[i]-brr[i]);
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        for(int i = 0 ;i  < arr.size() ; i++){
            ans += abs(arr[i]-brr[i]);
        }
        return min(ans,ans1);

    }
};