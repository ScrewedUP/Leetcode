class Solution {
public:
    int t[400];
    int solve(int i, set<int> &s,int e,vector<int> &c){
        if ( i > e ) return 0;
        if ( t[i] != -1 ) return t[i];
        int skip = INT_MAX;
        if ( s.find(i) == s.end()){
            skip = solve(i+1,s,e,c);
        }
        int nxt = c[0] + solve(i+1,s,e,c);
        int nxt7 = c[1] + solve(i+7,s,e,c);
        int nxt30 = c[2] + solve(i+30,s,e,c);
        return t[i] = min(skip,min(nxt,min(nxt7,nxt30)));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        set<int> s;
        for(auto it : days) s.insert(it);
        return solve(1,s,days[days.size()-1],costs);
    }
};