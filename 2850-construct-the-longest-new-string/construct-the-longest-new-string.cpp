class Solution {
public:
    int t[51][51][51][4];
    int solve(int x,int y, int z,int last){
        if ( x < 0 || y < 0 || z < 0 ) return 0;
        if ( t[x][y][z][last] != -1 ) return t[x][y][z][last];
        int cnt = 0;
        if ( last == 3 ){
            if ( x > 0){
                cnt = max(cnt,2+solve(x-1,y,z,0));
            }
            if ( y > 0){
                cnt = max(cnt,2 + solve(x,y-1,z,1));
            }
            if ( z > 0){
                cnt = max(cnt,2+solve(x,y,z-1,2));
            }
        
        }
        if ( last == 0 ){
            if ( y > 0 ){
                cnt = max(cnt,2 + solve(x,y-1,z,1));
            }
        }
        if ( last == 1){
            if ( x > 0){
                cnt = max(cnt,2+solve(x-1,y,z,0));
            }
            if ( z > 0 ){
                cnt = max(cnt,2+solve(x,y,z-1,2));
            }
        }
        if ( last == 2){
            if ( x > 0 ){
                cnt = max(cnt,2+solve(x-1,y,z,0));
            }
            if  (z > 0){
                cnt = max(cnt,2+solve(x,y,z-1,2));
            }
        }
        return t[x][y][z][last] = cnt;
    }
    int longestString(int x, int y, int z) {
        memset(t,-1,sizeof(t));
        return solve(x,y,z,3);
    }
};