class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int total = s.size();
        int oneCnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == '1' ) oneCnt++;
        }
        string t;
        int zeroCnt = total - oneCnt;
        for(int i = 0 ; i < oneCnt - 1 ; i++){
            t+='1';
        }
        for(int i = 0 ; i < zeroCnt ; i++){
            t+='0';
        }
        t+='1';
        return t;
    }
};