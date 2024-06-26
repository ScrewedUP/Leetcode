class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') {
                v[s[i] - 'a']++;
            }
        }
        string ans;
        string p;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                int mini = INT_MAX;
                int miniIndex = -1;
                for (int j = 0; j < 26; j++) {
                    if (v[j] < mini) {
                        mini = v[j];
                        miniIndex = j;
                    }
                }
                p += (miniIndex + 'a');
                v[miniIndex]++;
            }
        }
        sort(p.begin(),p.end());
        int j = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] != '?'){
                ans += s[i];
            }
            else{
                ans += p[j];
                j++;
            }
        }
        return ans;
    }
};
