class Solution {
public:
    const int M = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> v(26,0);
        for(int i = 0 ; i < s.size() ; i++){
            v[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t ; i++){
            long long aCnt = 0;
            long long bCnt = 0;
            for(int j = 25 ; j >= 0 ; j--){
                if ( j == 25 ){
                    if ( v[j] > 0 ){
                        aCnt += v[j];
                        bCnt += v[j];
                        v[j] = 0;
                    }
                }
                else{
                    v[j+1] += v[j];
                    v[j] = 0;
                }
            }
            v[0] = (v[0] + aCnt) % M;
            v[1] = ( v[1] + bCnt) %  M;
        }
        long long cnt = 0;
        for(auto it : v ){
            cnt = (cnt + it) % M;
        }
        return cnt;
    }
};