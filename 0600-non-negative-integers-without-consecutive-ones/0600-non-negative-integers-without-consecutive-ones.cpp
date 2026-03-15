class Solution {
public:
    string toBinary(int n) {
        if (n == 0) return "0";
        string s = bitset<32>(n).to_string();
        return s.substr(s.find('1'));
    }
    int dp[33][3][3];
    int solve(string &s,int idx,bool tight,int prev){
        if ( idx == s.size() ) return 1;
        if ( dp[idx][tight][prev] != -1 ) return dp[idx][tight][prev];
        int lb = 0;
        int ub = tight ? s[idx] - '0' : 1;
        int res = 0;
        for(int dig = lb ; dig <= ub ; dig++){
            if ( dig == 1 && prev == 1 )continue;
            res += solve(s,idx+1,(tight && dig == ub),dig==1);
        }
        return dp[idx][tight][prev] = res;
    }
    int findIntegers(int n) {
        string s = toBinary(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,0);
    }
};