class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) {
        unordered_map<int,int> m;
        for(auto it : b){
            m[it]++;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            if ( m.find(i) == m.end() && sum + i <= maxSum){
                cnt++;
                sum += i;
            }
        }
        return cnt;
    }
};