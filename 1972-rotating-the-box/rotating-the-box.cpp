class Solution {
public:
    /*
        ideas:
            first rotate by 90 deg
            start  from the last second row and for every stone 
            move it to the last position it can go
            while moving it update the cells


            [ 1 2 3 ]  =>  [4 1]      (0,0) => (0,1)
                           [5 2]      (1,0) => (0,0)
            [ 4 5 6 ]      [6 3]      (0,1) => (1,1)
    */
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> rot(n,vector<char>(m));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                rot[j][m-i-1] = boxGrid[i][j];
            }
        }
        n = rot.size();
        m = rot[0].size();
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < m ; j++){
                if ( rot[i][j] == '#'){
                    for(int k = i + 1 ; k < n ; k++){
                        if ( rot[k][j] == '.'){
                            rot[k][j] = '#';
                            rot[k-1][j] = '.';
                        }
                        else break;
                    }
                }
            }
        }
        return rot;
    }
};