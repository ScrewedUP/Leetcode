class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxi = INT_MIN;
        int i = 0;
        int j = h.size() - 1;
        while ( i < j ){
            maxi = max(maxi,min(h[i],h[j])*(j-i));
            if ( h[i] <= h[j] ){
                i++;
            }
            else j--;
        }
        return maxi;
    }
};