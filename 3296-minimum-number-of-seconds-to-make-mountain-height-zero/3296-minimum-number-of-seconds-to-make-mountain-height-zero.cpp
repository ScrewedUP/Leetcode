class Solution {
public:
    /*
        direct greedy fails

        51

        1 1 1 2 2 7 9


        66

        binary search on answer? answer is time

    */

    bool check(long long time,long long mh,vector<int>& wt){
        // this fun return that can the workers complete mh height each
        // working for a maximum time of time sec

        long long cnt = 0;

        for(int i = 0 ; i < wt.size() ; i++){
            // how much height can the ith worker reduce in time sec
            /*
                lets say x height 
                wt[i]*1 + wt[i]*2 + ..... + wt[i]*x = time;

                wt[i]*(1+2+3+...+x) = time;

                wt[i]*x*(x+1)/2 = time;

                x*(x+1) = 2*time/wt[i];

                x^2 + x = 2*time/wt[i];

                x^2 + x - 2*time/wt[i] = 0;

                x = -1 +- root(1 - 8*time/wt[i])/2
            */

            long long ans = (-1 + sqrtl(1 + (8LL*time)/wt[i]))/2;
            cnt += ans;
        }
        if ( cnt >= mh) return true;
        return false;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long mx = *max_element(wt.begin(),wt.end());
        long long l = 1;
        long long r = mx*(mh)*(mh+1)/2;
        long long ans = 0;
        while( l <= r){
            long long mid = (l+r)/2;

            if ( check(mid,mh,wt)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};