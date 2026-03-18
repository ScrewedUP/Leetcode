class Solution {
public:
    int d[8][2] = {{-1,0},{1,0},{1,-1},{-1,1},{0,-1},{0,1},{-1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
if(grid[0][0] || grid[n-1][n-1])return -1;    
        vector<vector<int>> vis(n,vector<int>(n,0));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        int count = 0;
////
        while(!q.empty()){
            count++;
            int x = q.size();
            while(x--){
                auto f = q.front();
                q.pop();
                if ( f.first == n - 1 && f.second == n - 1) return count;
                for(int i = 0 ; i < 8 ; i++){
                    int dx = f.first + d[i][0];
                    int dy = f.second + d[i][1];

                    if ( dx >= 0 && dx < n && dy >= 0 && dy < n && !vis[dx][dy] && grid[dx][dy] == 0){
                        q.push({dx,dy});
                        vis[dx][dy] = 1;
                    }

                }
            }
            
        }

        return -1;
    }
};