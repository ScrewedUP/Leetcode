class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> m;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            m[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i = 0 ; i < queries.size() ; i++){
            int curr = nums[queries[i]];
            if ( m[curr].size() < 2 ){
                ans.push_back(-1);
            }
            else{
                int x = lower_bound(m[curr].begin(),m[curr].end(),queries[i]) - m[curr].begin();
                int f = INT_MAX;
                int sz = m[curr].size();

                if ( x - 1 >= 0 ){
                    int d = abs(m[curr][x-1] - m[curr][x]);
                    f = min(f, min(d, n - d));
                } else {
                    int d = abs(m[curr][sz-1] - m[curr][x]);
                    f = min(f, min(d, n - d));
                }

                if ( x + 1 < sz ){
                    int d = abs(m[curr][x+1] - m[curr][x]);
                    f = min(f, min(d, n - d));
                } else {
                    int d = abs(m[curr][0] - m[curr][x]);
                    f = min(f, min(d, n - d));
                }

                ans.push_back(f);
            }
        }
        return ans;
    }
};
