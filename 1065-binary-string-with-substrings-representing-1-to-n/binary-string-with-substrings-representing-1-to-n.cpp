class Solution {
public:
    long long binaryToDecimal(string n){
	    string num = n;
	    long long dec_value = 0;
	    long long base = 1;
	    long long len = num.length();
	    for (int i = len - 1; i >= 0; i--) {
		    if (num[i] == '1')
			    dec_value += base;
		    base = base * 2;
	    }
	    return dec_value;
    }
    bool queryString(string s, int n) {
        map<long long,int> m;
        // long long maxi = binaryToDecimal(s);
        // if ( n > maxi ) return false;
        for(int i = 0 ; i < s.size() ; i++){
            string a;
            for(int j = i ; j < s.size() ; j++){
                a += s[j];
                if ( a.size() <= 10){
                    long long num = binaryToDecimal(a);
                    m[num]++;
                }
                else break;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if ( m.find(i) == m.end() ) return false;
        }
        return true;
    }
};