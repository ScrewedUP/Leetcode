class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n = p.size();
        vector<int> prefix(n);
        prefix[0] = p[0]==1?1:-1;
        for(int i = 1 ; i < n ; i++){
            if ( p[i] == 1 ){
                prefix[i] = 1 + prefix[i-1];
            }
            else{
                prefix[i] = prefix[i-1] - 1;
            }
        }
        for(int i = 0 ; i < n - 1 ; i++){
            if ( prefix[i] > prefix[n-1] - prefix[i] ) return i+1;
        }
        return -1;
    }
};