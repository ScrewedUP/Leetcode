class Solution {
public:
    int d[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        
        pq.push({0,0,0});
        
        while(!pq.empty()){
            int diff = get<0>(pq.top());
            int x    = get<1>(pq.top());
            int y    = get<2>(pq.top());
            pq.pop();
            
            if (x == n-1 && y == m-1) return diff;
            
            for(int i = 0 ; i < 4 ; i++){
                int dx = x + d[i][0];
                int dy = y + d[i][1];
                
                if (dx>=0 && dx<n && dy>=0 && dy<m){
                    int newDiff = abs(heights[x][y] - heights[dx][dy]);
                    int effort = max(diff, newDiff);
                    
                    if (dist[dx][dy] > effort){
                        dist[dx][dy] = effort;
                        pq.push({effort, dx, dy});
                    }
                }
            }
        }
        return 0;
    }
};