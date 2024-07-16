class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> all;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                all.push_back(grid[i][j]);
            }
        }
        sort(all.begin(),all.end());
        int xt = all[(all.size()/2)];
        bool ok = true;
        for(int i = 0 ;i < all.size() ; i++){
            int curr = all[i];
            // curr + n*x = xt;
            // n*x = xt - curr;
            // n = (xt - curr)/x;
            int n = abs(xt-curr) / x;
            if ( curr <= xt ){
                if ( curr + n*x != xt ){
                    ok = false;
                    break;
                }
            }
            else{
                if ( curr - n*x != xt ){
                    ok = false;
                    break;
                }
            }
            
        }
        if ( !ok ) return -1;
        else{
            int ans = 0;
            for(int i = 0 ; i < all.size() ; i++){
                int curr = all[i];
                int n = abs(xt-curr) / x;
                ans += n;
            }
            return ans;
        }
    }
};