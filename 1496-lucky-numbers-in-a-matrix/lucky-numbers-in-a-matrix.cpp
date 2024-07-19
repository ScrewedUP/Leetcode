class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        bool ok = false;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                int mini = *min_element(mat[i].begin(),mat[i].end());
                int maxi = INT_MIN;
                for(int k = 0 ; k < n ; k++){
                    maxi = max(maxi,mat[k][j]);
                }
                if ( mat[i][j] == mini && mat[i][j] == maxi){
                    ans.push_back(mat[i][j]);
                    ok = true;
                    break;
                }
            }
            if ( ok ) break;
        }
        return ans;
    }
};