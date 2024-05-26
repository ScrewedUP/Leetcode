class Solution {
public:
    string compressedString(string word) {
        string ans;
        int cnt = 0;
        for(int i = 0 ; i < word.size() - 1 ; i++){
            cnt++;
            if ( cnt == 9 ){
                ans += '9';
                ans += word[i];
                cnt = 0;
            }
            else if ( word[i] != word[i+1]){
                ans += cnt + '0';
                ans += word[i];
                cnt  = 0;
            }    
        }
        cnt++;
        ans += cnt + '0';
        ans += word[word.size() - 1];
        return ans;
    }
};