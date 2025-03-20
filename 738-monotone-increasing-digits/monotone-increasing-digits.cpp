class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        for(int i = s.size() - 1 ; i > 0 ;i--){
            if ( s[i] - '0' < s[i-1] - '0'){
                for(int j = i ; j < s.size() ; j++){
                    s[j] = '9';
                }
                int x = s[i-1] - '0';
                x--;
                s[i-1] = x + '0'; 
            }
        }
        int ans = stoi(s);
        return ans;
    }
};
// 1324
// 1299