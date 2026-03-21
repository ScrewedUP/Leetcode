class Solution {
public:
    /*
        (x,y) top left corner of sqauare, k is the side length

        coordinates of the sqaure 

            (x,y)       (x+k,y)


            (x,y+k)     (x+k,y+k)

    */
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int offset = 0;
        for(int i = x ; i < (k/2 + x) ; i++){
            for(int j = y ; j < y+k ; j++){
                swap(grid[i][j],grid[x + k - 1 - offset][j]);
            }
            offset++;
        }
        return grid;
    }
};