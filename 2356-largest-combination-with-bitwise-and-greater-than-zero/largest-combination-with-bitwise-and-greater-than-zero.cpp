class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> v(32,0);
        for(int i = 0 ; i < c.size() ; i++){
            for(int j = 31 ; j >= 0 ; j--){
                if ( c[i] & (1 << j) ){
                    v[j]++;
                }
            }
        }
        return *max_element(v.begin(),v.end());
    }
};