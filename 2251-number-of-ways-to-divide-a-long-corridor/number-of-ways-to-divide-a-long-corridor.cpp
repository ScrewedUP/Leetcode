class Solution {
public:
    const int M = 1e9 + 7;
    int numberOfWays(string corridor) {
        int seats = 0;
        for(int i = 0 ; i < corridor.size() ; i++){
            if ( corridor[i] == 'S' ) seats++;
        }
        if ( seats&1 || seats == 0) return 0;
        long long ways = 1;
        int curr = 0;
        int plant = 0;
        for(int i = 0 ;i < corridor.size() ; i++){
            if ( corridor[i] == 'S' && i != corridor.size()-1){
                curr++;
                if ( curr == 3 ){
                    curr = 1;
                    if ( plant > 0 ) ways = (ways%M *(plant+1)%M)%M;
                    plant = 0;
                }
            }
            else if ( corridor[i] == 'P' && curr == 2 ) plant++;
        }
        return ways % M;
    }
};