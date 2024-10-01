class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        for(auto it : arr) m[it]++;
        map<int,int> m2;
        for(auto it : m){
            m2[it.second]++;
        }
        for(auto it : m2 ){
            if ( it.second > 1 ) return false;
        }
        return true;
    }
};