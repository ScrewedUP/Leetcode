class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int l = 0;
        vector<int> v(26,0);
        int maxi = 0;
        for(int i = 0 ; i < s.size(); i++){
            v[s[i] - 'a']++;
            if ( i - l + 1 == k){
                int curr = 0;
                for(int j = 0 ; j < 26 ; j++){
                    if ( isVowel(j+'a')){
                        curr += v[j];
                    }
                }
                v[s[l]-'a']--;
                l++;
                maxi = max(maxi,curr);
            }
        }
        return maxi;
    }
};