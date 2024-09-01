class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>> ans;
        if ( o.size() != m*n ) return ans;
        vector<int> temp;
        int k = 0;
        for(int i = 0 ; i < o.size() ; i++){
            temp.push_back(o[i]);
            k++;
            if ( k == n ){
                ans.push_back(temp);
                temp.clear();
                k = 0;
            }
        
        }
        return ans;
    }
};