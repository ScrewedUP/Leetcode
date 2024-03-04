class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int ans = 0;
        int cnt = 0;
        int  i = 0 ; int j = token.size() - 1;
        while( i <= j ){
            if ( cnt == 0 && power < token[i] ) break;
            if ( power >= token[i] ){
                cnt++;
                power -= token[i];
                ans = max(cnt,ans);
                i++;
            }
            else{
                if ( cnt > 0 ){
                    power += token[j];
                    j--;
                    cnt--;
                }
                else break;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};