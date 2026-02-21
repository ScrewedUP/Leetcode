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
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int old = image[sr][sc];
        if (old == color) return image; 

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int dx = x + d[i][0];
                int dy = y + d[i][1];

                if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                    image[dx][dy] == old)
                {
                    image[dx][dy] = color;
                    q.push({dx,dy});
                }
            }
        }
        return image;
    }
};