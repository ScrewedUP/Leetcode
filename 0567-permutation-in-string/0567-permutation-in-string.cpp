class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0);
        vector<int> b(26,0);

        for(auto c : s1) a[c-'a']++;
        int x = s1.size();

        int l = 0;
        for(int i = 0 ; i < s2.size() ; i++){
            b[s2[i] - 'a']++;

            if ( i - l + 1 == x){
                bool ok = true;
                for(int j = 0 ; j < 26 ; j++){
                    if ( a[j] != b[j]){
                        ok = false;
                    }
                }

                if ( ok ) return true;
                b[s2[l] - 'a']--;
                l++;
            }
        }
        return false;

        return true;
    }
};