class Solution {
public:
    /*
        [4,3,2,1]
        [0,0,0,0,0]
        queries:
            [1,3]
        [0,1,0,0,-1]
            [0,2]
        [1,1,0,-1,-1]
        Prefix Sum:
        [1,2,2,1,1]
    */
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> v(n+1,0);
        for(int i = 0 ; i < q.size() ; i++){
            v[q[i][0]]++;
            v[q[i][1]+1]--;
        }
        vector<int> pre(n);
        pre[0] = v[0];
        for(int i = 1 ; i < n ; i++){
            pre[i] = v[i] + pre[i-1];
        }
        for(int i = 0 ; i < n ; i++){
            if ( pre[i] < nums[i]) return false;
        }
        return true;
    }
};