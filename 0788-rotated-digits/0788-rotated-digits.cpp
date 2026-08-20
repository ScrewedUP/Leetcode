class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            string s = to_string(i);
            bool ok = false;
            int tempC = 0;
            for(auto &ch : s){
                if ( ch == '2' || ch == '5' || ch == '6' || ch == '9'){
                    ok = true;
                }
                else if ( ch == '3' || ch == '4' || ch == '7'){
                    ok = false;
                    break;
                }
            }

            if ( ok ){
                cnt++;
            }
        }
        return cnt;
    }
};