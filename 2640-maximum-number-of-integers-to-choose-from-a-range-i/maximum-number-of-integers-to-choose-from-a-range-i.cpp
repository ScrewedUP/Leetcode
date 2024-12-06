class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) {
        vector<int> m(1e4+1,0);
        for(auto it : b){
            m[it]++;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            if ( m[i] == 0 && sum + i <= maxSum){
                cnt++;
                sum += i;
            }
        }
        return cnt;
    }
};