class Solution {
public:
    int passThePillow(int n, int time) {
        int x = 0;
        int where = 1;
        while ( time > 0){
            if ( x % 2 == 0){
                where++;
                if ( where == n ) x++;
            }
            else{
                where--;
                if ( where == 1 ) x++;
            }
            time--;
        }
        return where;
    }
};