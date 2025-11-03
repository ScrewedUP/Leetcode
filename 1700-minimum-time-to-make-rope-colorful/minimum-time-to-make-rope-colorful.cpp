class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l = 0;
        int r = 0;
        int ans = 0;
        while ( r < colors.size()){
            if ( r == 0 ){
                r++;
            }
            else{
                if ( colors[r] != colors[l]){
                    l = r;
                    r++;
                }
                else{
                    int time1 = neededTime[r];
                    int time2 = neededTime[l];
                    if ( time1 <= time2){
                        ans += time1;
                        r++;
                    }
                    else{
                        ans += time2;
                        r++;
                        l = r-1;
                    }
                }
            }
        }
        return ans;
    }
};