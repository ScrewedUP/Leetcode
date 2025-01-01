class Solution {
public:
    int maxScore(string s) {
        vector<int> pre(s.size());
        pre[0] = s[0] - '0';
        for(int i = 1 ; i < s.size() ; i++){
            pre[i] = pre[i-1] + s[i] - '0'; 
        }
        int maxi = INT_MIN;
        int n = s.size();
        for(int i = 0 ; i < s.size() - 1 ; i++){
            int x = i - pre[i] + 1;
            int y = pre[n-1] - pre[i];
            maxi = max(maxi,x+y);
        }
        return maxi;
    }
};