class Solution {
public:
    long long ceil(long long x, long long y){
        if (x % y == 0) {
            return x / y;
        }
        return x / y + 1;
    }
    bool check(int x,int n,vector<int> &v){
        long long cnt = 0;
        for(int i = 0 ;i < v.size() ; i++){
            cnt += ceil(v[i],x);
        }
        if ( cnt <= n ) return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& v) {
        long long sum = 0;
        for(auto it : v ) sum += it;
        long long low = 1;
        long long high = sum;
        long long ans = sum;
        while( low <= high ){
            long long mid = (low + high)/2;
            if ( check(mid,n,v) ){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};