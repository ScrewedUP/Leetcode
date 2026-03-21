class Solution {
public:
    /*
        (x,y) top left corner of sqauare, k is the side length

        coordinates of the sqaure 

            (x,y)       (x+k,y)


            (x,y+k)     (x+k,y+k)

            k = 7;
            0,6
            1,5
            2,4
            k - i - offset
            [14,3,18,16]
            [2,14,11,20]
            [19,19,4,15]
            [11,15,18,6]
            [x,y,z,t]
            [x,y,z,t]
            [x,y,z,t]
    */
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int offset = 0;
        for(int i = x ; i < (k/2 + x) ; i++){
            // cout << i << " ";
            for(int j = y ; j < y+k ; j++){
                cout << "|" << i << ":" << j << "|" << "<->" << i+k-1-offset << ":" << j << endl;
                swap(grid[i][j],grid[x + k - 1 - offset][j]);
            }
            offset++;
        }
        return grid;
    }
};