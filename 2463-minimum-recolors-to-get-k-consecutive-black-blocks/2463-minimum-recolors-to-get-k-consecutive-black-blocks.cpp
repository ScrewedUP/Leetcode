class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int bc = 0;
        int l = 0;
        int n = blocks.size();
        for(int r = 0 ; r < n ; r++){
            if ( blocks[r] == 'B') bc++;
            if ( r - l + 1 == k){
                int req = k - bc;
                ans = min(ans,req);
                if ( blocks[l] == 'B') bc--;
                l++;
            }
        }
        
        return ans;
    }
};