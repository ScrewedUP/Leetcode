class Solution {
public:
    /*
        Observations and ideas : 
            m x n grid
            image[sr][sc] is the source where we have to start
            we have color from the start we need to color all the 
            neighbours whose value is the same as the current block

            this seems like level by level colouring 
            BFS seems ideal here considering level order traversal
            but DFS can do the same thing and easier without queue

    */

    int n,m;
    void dfs(int i,int j,vector<vector<int>> &image,int c,int nc){
        if ( i >= n || i < 0 || j >= m || j < 0 || image[i][j] != c || image[i][j] == nc){
            return;
        }

        image[i][j] = nc;

        dfs(i-1,j,image,c,nc);
        dfs(i+1,j,image,c,nc);
        dfs(i,j-1,image,c,nc);
        dfs(i,j+1,image,c,nc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        n = image.size();
        m = image[0].size();
        dfs(sr,sc,image,startColor,color);
        return image;
    }
};