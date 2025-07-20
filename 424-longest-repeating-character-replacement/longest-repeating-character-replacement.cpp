class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int n = s.size();
        for(int i = 0 ; i < 26 ; i++){
            char c = 'A' + i;
            int l = 0;
            int cnt = 0;
            int currMaxi = 0;
            for(int r = 0 ; r < n ; r++){
                if ( s[r] != c ){
                    cnt++;
                }
                while(cnt > k){
                    if ( s[l] != c){
                        cnt--;
                    }
                    l++;
                }
                currMaxi = max(currMaxi,r-l+1);
            }
            maxi = max(maxi,currMaxi);
        }
        return maxi;
    }
};