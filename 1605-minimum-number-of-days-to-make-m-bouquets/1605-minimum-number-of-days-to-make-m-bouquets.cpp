class Solution {
public:
    bool canPlace(int mid , vector<int>& v, int m, int k ){
        int cnt = 0;
        int count = 0;
        for(int i = 0 ; i < v.size() ; i++){
            if ( v[i] <= mid ){
                count++;
                if ( count == k){
                    cnt++;
                    count = 0;
                }
            }
            else count = 0;
        }
        if ( cnt >= m ) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ( (long long)m*k > bloomDay.size() ) return -1;
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = 0;
        while( low <= high ){
            int mid = low + (high - low)/2;
            if ( canPlace(mid,bloomDay,m,k) ){
                ans = mid ;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};