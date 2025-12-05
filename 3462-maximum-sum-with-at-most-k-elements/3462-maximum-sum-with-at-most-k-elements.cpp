class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> candidates;
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            sort(grid[i].rbegin(),grid[i].rend());
            for(int j = 0 ; j < limits[i] ; j++){
                candidates.push_back(grid[i][j]);
            }
        }
        sort(candidates.rbegin(),candidates.rend());
        long long sum = 0;
        int i = 0;
        while(k--){
            sum += candidates[i];
            i++;
        }
        return sum;
    }
};