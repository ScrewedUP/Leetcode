class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if ( mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while ( !q.empty() ){
            int x = q.size();
            time++;
            while(x--){
                auto t = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int d_x = t.first + dx[i];
                    int d_y = t.second + dy[i];

                    if ( d_x < n && d_x >= 0 && d_y < m && d_y >=0 ){
                        if ( mat[d_x][d_y] == 1){
                            int ct = time;
                            if ( ans[d_x][d_y] == INT_MAX ){
                                ans[d_x][d_y] = ct;
                                q.push({d_x,d_y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};