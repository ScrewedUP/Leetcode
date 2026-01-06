class Solution {
public:
    long long ceil(long long x,long long y){
        if ( x % y == 0) return x/y;
        return x/y + 1;
    }
    int ok(long long t,vector<int> &v,int h){
        long long cnt = 0;
        for(int i = 0 ; i < v.size() ; i++){
            cnt += ceil(v[i],t);
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans = INT_MAX;
        while(low <= high){
            long long mid = (low+high)/2;
            if ( ok(mid,piles,h)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};