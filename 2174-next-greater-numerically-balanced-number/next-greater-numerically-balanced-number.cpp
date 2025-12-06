class Solution {
public:
    bool ok(string s){
        map<int,int> m;
        for(auto it : s){
            m[it-'0']++;
        }
        for(auto it : m){
            if ( it.first != it.second) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if(n >= 666666) return 1224444;
        for(int i = n+1 ; i <= 10000001 ; i++ ){
            if ( ok(to_string(i))){
                return i;
            }
        }
        return n;
    }
};