class Solution {
    
    bool isSafe(int r, int c, int n, int m){
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    
    void safetyBFS(vector<vector<int>>& grid, int n, int m, vector<vector<int>> vis, int dx[], int dy[]){
        queue<pair<int,pair<int,int>>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({0 , {i,j}});
                }
            }
        }
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            grid[row][col] = dis;
            
            q.pop();
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(isSafe(nrow, ncol, n, m) && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({ dis+1, {nrow, ncol}});
                }
            }
            
        }
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] || grid[n-1][m-1]) return 0;
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        safetyBFS(grid, n, m, vis, dx, dy);
        
        int safeFactor = 1e9;
        
        priority_queue<pair<int,pair<int,int>>> pq;        
        pq.push({grid[0][0], {0,0}});        
        vis[0][0] = 1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            safeFactor = min(safeFactor, val);            
            if(row == n-1 && col == m-1) break;
            
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(isSafe(nrow, ncol, n, m) && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    int adjVal = grid[nrow][ncol];
                    pq.push({adjVal, {nrow, ncol}});
                }
            }
            
        }        
        return safeFactor;
        
    }
};