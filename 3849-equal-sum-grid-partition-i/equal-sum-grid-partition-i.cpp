class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> h(n),v(m);
        long long sum = 0;
        long long currSum = 0;
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                sum += grid[i][j];
                currSum += grid[i][j];
            }
            h[i] = currSum;
        }
        currSum = 0;
        for(int j = 0 ; j < m ; j++){
            
            for(int i = 0 ; i < n ; i++){
                currSum += grid[i][j];
            }
            v[j] = currSum;
        }
        for(int i = 0 ; i < n ; i++){
            if ( sum - h[i] == h[i] ) return true;
        }

        for(int j = 0 ; j < m ; j++){
            if ( sum - v[j] == v[j] ) return true;
        }

        return false;

    }
};