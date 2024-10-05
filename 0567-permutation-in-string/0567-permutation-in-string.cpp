class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n){
            return false;
        }
        vector<int>smpp(26,0);
        vector<int>pmpp(26,0);
        int i = 0;
        int j = 0;
        while(i<m){
            smpp[s2[i]-'a']++;
            pmpp[s1[i]-'a']++;
            i++;
        }
        if(smpp == pmpp){
            return true;    
        }
        while(i<n){
            smpp[s2[j++]-'a']--;
            smpp[s2[i++]-'a']++;
            if(smpp == pmpp){
                return true;
            }
        }
        return false;
    }
};