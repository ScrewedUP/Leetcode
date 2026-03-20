class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t = "";
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == ' '){
                if ( t.size() > 0 ){
                    v.push_back(t);
                    t = "";
                }
            }
            else{
                t += s[i];
            }
        }
        if ( t.size() > 0 ) v.push_back(t);
        reverse(v.begin(),v.end());
        for(auto it : v) cout << it << " ";
        string ans;
        for(int i = 0 ; i < v.size() ; i++){
            if ( i == v.size() - 1 ){
                ans += v[i];
            }
            else {
                ans += v[i];
                ans += ' ';
            }
        }
        return ans;
    }
};