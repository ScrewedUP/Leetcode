class Solution {
public:
    bool uniformArray(vector<int>& v) {
        sort(v.begin(),v.end());
        if ( v[0] & 1 ) return true;
        for(int i = 0 ; i < v.size() ; i++){
            if ( v[i] & 1 ) return false;
        }

        return true;
    }
};