class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        vector<bool> vis(h.size()+1,false);
        long long sum = 0;
        int cnt = 0 ;
        for(int i = 0 ; i < h.size() ; i++){
            if ( k == 0 ) break;
            if ( h[i] - cnt >= 0 ) sum += h[i] - cnt;
            cnt++;
            k--;
        }
        return sum;
    }
};