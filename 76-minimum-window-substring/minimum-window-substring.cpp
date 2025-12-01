class Solution {
public:
    bool check(vector<int> &v,vector<int> &t,char l){
        if ( l >= 'a'){
            v[l - 'a']--;
        }
        else{
            v[l - 'A' + 26]--;
        }
        for(int i = 0 ; i < t.size() ; i++){
            if ( t[i] > 0 ){
                if ( v[i] < t[i]){
                    if ( l >= 'a'){
                        v[l - 'a']++;
                    }
                    else{
                        v[l - 'A' + 26]++;
                    }
                    return false;
                }
            }
        }
        if ( l >= 'a'){
            v[l - 'a']++;
        }
        else{
            v[l - 'A' + 26]++;
        }
        // cout << "here1" << endl;
        return true;
    }
    bool ok(vector<int> &v,vector<int> &t){
        for(int i = 0 ; i < t.size() ; i++){
            if ( t[i] > 0 ){
                if ( v[i] < t[i]) return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> tar(53,0);
        for(int i = 0 ; i < t.size() ; i++){
            if ( t[i] >= 'a'){
                tar[t[i] - 'a']++;
            }
            else{
                tar[t[i] - 'A' + 26]++;
            }
            
        }
        vector<int> v(53,0);
        int n = s.size();
        int st = -1;
        int en = -1;
        int len = INT_MAX;
        int l = 0;
        for(int i = 0 ; i < n ; i++){
            if ( s[i] >= 'a'){
                v[s[i] - 'a']++;
            }
            else{
                v[s[i] - 'A' + 26]++;
            }
            if ( ok(v,tar) ){
                // if ( i == 10 ) cout << "here";
                while(check(v,tar,s[l])){
                    if ( s[l] >= 'a'){
                        v[s[l] - 'a']--;
                    }
                    else{
                        v[s[l] - 'A' + 26]--;
                    }
                    l++;
                }    
            }
            if ( ok(v,tar)){
                if ( i - l + 1 < len){
                    st = l;
                    en = i;
                    len = i - l + 1;
                }
                
            }
        }
        // cout << st << " " << en;
        if ( st == -1 ) return "";
        return s.substr(st,en-st+1);
        // return s.substr(st,en-st+1);
    }
};