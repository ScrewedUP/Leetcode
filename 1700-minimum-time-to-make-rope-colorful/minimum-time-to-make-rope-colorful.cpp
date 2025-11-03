class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l = 0;
        int r = 1;
        int ans = 0;
        while ( r < colors.size()){
            if ( colors[r] != colors[l]){
                l = r;
                r++;
            }
            else{
                if ( neededTime[r] <= neededTime[l]){
                    ans += neededTime[r];
                    r++;
                }
                else{
                    ans += neededTime[l];
                    r++;
                    l = r-1;
                }
            
            }
        }
        return ans;
    }
};