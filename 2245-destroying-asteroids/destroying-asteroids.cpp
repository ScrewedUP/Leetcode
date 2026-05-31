class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long x = mass;
        for(int i = 0 ; i < a.size() ; i++){
            if ( x >= a[i]){
                x += a[i];
            }
            else return false;
        }
        return true;
    }
};