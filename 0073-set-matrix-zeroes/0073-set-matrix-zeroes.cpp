class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> made(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( matrix[i][j] == 0 && made[i][j] == 0){
                    for(int k = 0 ; k < m ; k++){
                        if ( matrix[i][k] != 0) made[i][k] = 1;
                        matrix[i][k] = 0;
                        
                    }
                    for(int k = 0 ; k < n ; k++){
                        if ( matrix[k][j] != 0) made[k][j] = 1;
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};