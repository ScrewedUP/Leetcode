class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == 2 ){
                    q.push({i,j});
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int x = q.size();
            bool ok = false;
            for(int j = 0 ; j < x ; j++){
                auto f = q.front(); q.pop();
                
                for(int i = 0 ; i < 4 ; i++){
                    int dx = f.first + d[i][0];
                    int dy = f.second + d[i][1];

                    if ( dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 1){
                        ok = true;
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                    }
                }
            }
            if ( ok ) cnt++;
            
        }
        for(int i = 0 ;i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == 1 ){
                    return -1;
                }
            }
        }
        return cnt;
    }
};