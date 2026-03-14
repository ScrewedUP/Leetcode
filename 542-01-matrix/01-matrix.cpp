class Solution {
public:
    int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
            seems like a multisource bfs question
        */

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int time = 0;
        while( !q.empty()){
            time++;
            int x = q.size();
            while(x--){
                auto f = q.front();q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int dx = d[i][0] + f.first;
                    int dy = d[i][1] + f.second;

                    if ( dx < n && dx >= 0 && dy < m && dy >= 0 && mat[dx][dy] == 1){
                        if ( ans[dx][dy] > time ){
                            ans[dx][dy] = time;
                            q.push({dx,dy});
                        }
                    }
                }
            }
        }
        return ans;
    }
};