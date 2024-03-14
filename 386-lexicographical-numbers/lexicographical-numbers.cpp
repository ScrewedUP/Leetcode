class Solution {
public:
    void solve(int curr , int n , vector<int> &ans){
        if ( curr <= n ) ans.push_back(curr);
        else return ;

        for(int i = 0 ; i < 10 ; i++){
            solve(curr*10 + i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1 ; i < 10 ; i++){
            solve(i,n,ans);
        }
        return ans;
    }
};