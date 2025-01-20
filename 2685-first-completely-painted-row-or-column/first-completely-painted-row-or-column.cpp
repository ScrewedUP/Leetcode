class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        vector<pair<int, int>> v(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0 ; i < m*n ; i++){
            int currentElement = arr[i];
            int currentElementRow = v[arr[i]].first;
            int currentElementColumn = v[arr[i]].second;
            row[currentElementRow]++;
            if ( row[currentElementRow] == m ) return i;
            col[currentElementColumn]++;
            if ( col[currentElementColumn] == n ) return i;            
            
        }
        return arr.size() - 1;
    }
};