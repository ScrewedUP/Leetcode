#define INF 1e9
class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       queue<pair<int,int>> q;
       vector<vector<int>> dis(n,vector<int>(m,INF)); 
       for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front(); q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int dx = f.first + d[i][0];
                    int dy = f.second + d[i][1];
                    auto ok = [&](int a,int b){
                        return a >= 0 && b >= 0 && a < n && b < m;
                    };
                    if ( ok(dx,dy) && mat[dx][dy] == 1 && dis[dx][dy] == INF){
                        dis[dx][dy] = min(dis[dx][dy],dis[f.first][f.second] + 1);
                        q.push({dx,dy});
                    }
                }
            }
        }
        return dis;
    }
};