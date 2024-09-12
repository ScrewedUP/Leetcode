class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> m;
        for(auto it : allowed) m[it]++;
        int cnt = 0;
        for(auto it : words){
            bool ok = true;
            for(int i = 0 ; i < it.size() ; i++){
                if ( m.find(it[i]) == m.end()) ok = false;
            }
            if ( ok ) cnt++;
        }
        return cnt;
    }
};