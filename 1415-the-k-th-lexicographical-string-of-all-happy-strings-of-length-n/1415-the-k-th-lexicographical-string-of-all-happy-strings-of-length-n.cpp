class Solution {
public:
    vector<string> ans;
    void solve(string s,int n,int l){
        if ( s.size() == n){
            ans.push_back(s);
            return;
        }

        if ( l == 0){
            solve(s + "a",n,1);
            solve(s + "b",n,2);
            solve(s + "c",n,3);
        }
        else if ( l == 1){
            solve(s + "b",n,2);
            solve(s + "c",n,3);
        }
        else if ( l == 2){
            solve(s + "a",n,1);
            solve(s + "c",n,3);
        }
        else if ( l == 3){
            solve(s + "a",n,1);
            solve(s + "b",n,2);
        }
    }
    string getHappyString(int n, int k) {
        solve("",n,0);
        sort(ans.begin(),ans.end());
        if ( ans.size() < k ) return "";
        return ans[k-1];
    }
};