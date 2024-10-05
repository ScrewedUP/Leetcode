class Solution {
public:
    int addMinimum(string word) {
        string v = "abc";
        int cnt = 0;
        int j = 0;
        for(int i = 0 ;i < word.size() ; i++){
            if ( word[i] == v[j%3] ){
                j++;
                continue;
            }
            cnt++;
            j++;
            i--;
        }
        // if ( j != 0 ){
        //     cnt += 2 - j;
        // }
        cnt += (( 3 - j%3)%3);
        return cnt;
    }
};