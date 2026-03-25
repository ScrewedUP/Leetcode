class Solution {
public:
    bool uniformArray(vector<int>& v) {
        sort(v.begin(),v.end());
        int x = v[0];

        if ( x % 2 == 1 ){
            return true;
        }

        for(int i = 0 ; i < v.size() ; i++){
            if ( v[i] & 1 ) return false;
        }

        return true;
    }
};