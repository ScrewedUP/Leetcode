class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> v(101,0);
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = nums[i][0] ; j <= nums[i][1] ; j++){
                v[j]++;
            }
        }
        int cnt = 0;
        for(int i = 0 ;i < v.size() ; i++){
            if ( v[i] > 0 ) cnt++;
        }
        return cnt;
    }
};