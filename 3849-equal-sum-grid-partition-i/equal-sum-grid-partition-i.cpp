class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> h(n);
        vector<long long> v(m);
        for(int i = 0 ; i < grid.size() ; i++){
            long long currSum = 0;
            for(int j  = 0 ; j < grid[0].size() ; j++){
                sum += grid[i][j];
                currSum += grid[i][j];
            }
            h[i] = currSum;
        }

        for(int j = 0 ; j < m ; j++){
            long long currSum = 0;
            for(int i = 0 ; i < n ; i++){
                currSum += grid[i][j];
            }
            v[j] = currSum; 
        }

        long long c = 0;
        for(int i = 0 ; i < n ; i++){
            c += h[i];
            if ( sum - c == c ){
                return true;
            }
        }
        c = 0;
        for(int j = 0 ; j < m ; j++){
            c += v[j];
            if ( sum - c == c ){
                return true;
            }
        }

        return false;
    }
};