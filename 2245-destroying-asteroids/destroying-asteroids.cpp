class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long x = mass;
        for(auto& i : a){
            if ( x >= i ) x += i;
            else return false;
        }
        return true;
    }
};