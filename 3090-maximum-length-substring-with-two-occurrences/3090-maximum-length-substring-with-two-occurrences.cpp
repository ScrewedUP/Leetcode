class Solution {
public:
    bool isOkay(vector<int> &v){
        bool ok = true;
        for(int j = 0 ; j < 26 ; j++){
            if ( v[j] > 2 ){
                ok = false;
                break;
            }
        }

        return ok;
    }
    int maximumLengthSubstring(string s) {
        vector<int> v(26,0);

        int l = 0;
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            v[s[i] - 'a']++;

            bool ok = isOkay(v);

            

            if ( ok ){
                ans = max(ans,i-l+1);
            }
            else while(!isOkay(v)){
                v[s[l]-'a']--;
                l++;
            }
        }

        return ans;
    }
};