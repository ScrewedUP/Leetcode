class Solution {
public:
    bool ok(int i,int t){
        int p = 1;
        while(i>0){
            int d = i%10;
            p*=d;
            i/=10;
        }
        return p%t == 0;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 1001 ; i++){
            if ( ok(i,t)) return i;
        }
        return 0;
    }
};