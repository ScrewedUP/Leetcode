class Solution {
public:
    set<vector<int>> ans;
    void solve(int i,int n,int k ,int var,vector<int> &temp){
        if ( i > n + 1 ) return;
        if ( k == 0 && temp.size() == var){
            ans.insert(temp);
        }
        temp.push_back(i);
        solve(i+1,n,k-1,var,temp);
        temp.pop_back();
        k++;
        solve(i+1,n,k-1,var,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        for(int i = 1 ; i <= n ; i++){
            int var = k;
            solve(i,n,k,var,temp);
        }
        vector<vector<int>> ans1;
        for(auto it : ans) ans1.push_back(it);
        return ans1;    
    }
};