class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> m;
        for(auto it : arr) m[it]++;
        for(auto it : target ){
            if ( m.find(it) == m.end() ) return false;
            else{
                m[it]--;
                if ( m[it] == 0 ) m.erase(it);
            }
        }
        return true;
    }
};