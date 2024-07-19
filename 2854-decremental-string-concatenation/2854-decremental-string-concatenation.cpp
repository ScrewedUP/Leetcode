class Solution {
public:
    int t[1001][26][26];
    int solve(int idx ,vector<string>& v,int first,int last){
        if ( idx >= v.size() ) return 0;
        if ( t[idx][first][last] != -1 ) return t[idx][first][last];
        int currFirst = v[idx][0] - 'a';
        int currLast = v[idx][v[idx].size() - 1] - 'a';
        int cont = 0;
        int rev = 0;
        // 1 2
        if ( last == currFirst){
            cont = v[idx].size() - 1 + solve(idx+1,v,first,currLast);
        }
        else{
            cont = v[idx].size() + solve(idx+1,v,first,currLast);
        }

        if ( currLast == first) {
            rev = v[idx].size() - 1 + solve(idx+1,v,currFirst,last);
        }
        else{
            rev = v[idx].size()  + solve(idx+1,v,currFirst,last);
        }
        return t[idx][first][last] = min(cont,rev);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(t,-1,sizeof(t));
        return words[0].size() + solve(1,words,words[0][0] - 'a' , words[0][words[0].size() - 1] - 'a');
    }
};