class Solution {
public:
    bool check(int x, vector<int> &c , long long k){
        long long cnt = 0;
        int n = c.size();
        for(int i = 0 ; i < n ; i++){
            cnt += c[i]/x;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& c, long long k) {
        int low = 1;
        int high = 1e9;
        int ans = 0;
        while ( low <= high){
            int mid = (high+low)/2;
            if ( check(mid,c,k) ){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};