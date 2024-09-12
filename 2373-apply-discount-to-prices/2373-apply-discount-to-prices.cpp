class Solution {
public:
    bool check(string &s){
        if ( s.size() <= 1 ) return false;
        if ( s[0] != '$' ) return false;
        for(int i = 1; i < s.size() ; i++){
            if ( s[i] - '0' < 0 || s[i] - '0' > 9 ) return false;
        }
        return true;
    }
    string discountPrices(string s, int d) {
        vector<string> w;
        string curr = "";
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == ' '){
                if ( check(curr)){
                    string n;
                    for(int j = 1 ; j < curr.size() ; j++){
                        n += curr[j];
                    }
                    double num = stod(n);
                    num -= num*(d*1.0/100);
                    stringstream ss;
            ss << fixed << setprecision(2) << num;
            curr = "$" + ss.str();

                }
                w.push_back(curr);
                curr = "";
            }
            else{
                curr += s[i];
            }
        }
        if ( check(curr)){
                    string n;
                    for(int j = 1 ; j < curr.size() ; j++){
                        n += curr[j];
                    }
                    double num = stod(n);
                    num -= num*(d*1.0/100);
                    stringstream ss;
                    ss << fixed << setprecision(2) << num;
                    curr = "$" + ss.str();

                }
                w.push_back(curr);
        string ans;
        for(int i = 0 ; i < w.size() ; i++){
            ans += w[i];
            if ( i != w.size() - 1){
                ans += ' ';
            }
        }
        return ans;
    }
};