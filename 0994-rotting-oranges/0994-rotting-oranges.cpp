class Solution {
public:
    int n,m;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int o = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == 2) q.push({i,j});
                if ( grid[i][j] == 1 ) o++;
            }
        }
        if ( o == 0 ) return 0;
        int cnt = 0;
        while( !q.empty()){
            cnt++;
            int x = q.size();
            for(int i = 0 ; i < x ; i++){
                auto front = q.front();
                q.pop();
                if ( front.first+1 < n && grid[front.first+1][front.second] == 1){
                    grid[front.first+1][front.second] = 2; 
                    q.push({front.first+1,front.second});
                    
                }
                if ( front.first-1 >= 0 && grid[front.first-1][front.second] == 1){
                    grid[front.first-1][front.second] = 2; 
                    q.push({front.first-1,front.second});
                    
                }
                if ( front.second+1 < m && grid[front.first][front.second+1] == 1){
                    grid[front.first][front.second+1] = 2; 
                    q.push({front.first,front.second+1});
                    
                }
                if ( front.second-1 >= 0 &&grid[front.first][front.second-1] == 1){
                    grid[front.first][front.second-1] = 2; 
                    q.push({front.first,front.second-1});
                    
                }
                
            }
        }
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return cnt - 1;
        //bfs

    }
};

/*
                2   2   2
                0   2   2
                1   0   2

*/