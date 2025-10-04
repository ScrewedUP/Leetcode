class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = INT_MIN;
        int i = 0 ;
        int j = h.size() - 1;
        while ( i < j){
            int p = min(h[i],h[j]);
            ans = max(ans,p*(j-i));
            if ( h[i] < h[j]){
                i++;
            }
            else j--;
        }
        return ans;
    }
};