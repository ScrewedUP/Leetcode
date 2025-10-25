class Solution {
public:
    int totalMoney(int n) {
        int mon = 1;
        int ans = mon;
        int curr = mon;
        int cnt = 1;
        for(int i = 1 ; i < n; i++){
            if ( cnt == 7){
                mon++;
                ans += mon;
                curr = mon;
                cnt = 0;
            }
            else{
                curr++;
                ans += curr;
            }
            
            cnt++;
        }
        return ans;
    }
};