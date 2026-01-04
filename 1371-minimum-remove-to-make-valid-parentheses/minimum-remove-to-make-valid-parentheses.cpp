class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int o = 0;
        int cnt = 0;
        vector<int> v;
        unordered_map<int,int> m,m2;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == '('){
                o++;
                v.push_back(i);
            }
            else if ( s[i] == ')'){
                if ( o > 0){
                    o--;
                    v.pop_back();
                }
                else{
                    m[i]++;
                }
            }
        }
        for(auto it : v) m2[it]++;
        string ans;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == '('){
                if ( m2.find(i) == m2.end()){
                    ans += s[i];
                }
            }
            else if ( s[i] == ')'){
                if ( m.find(i) == m.end()){
                    ans += s[i];
                }
            }
            else ans += s[i];
        }
        return ans;
    }
};