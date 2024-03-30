class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int len = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            int ans = 0;
            for(int j = i ; j < nums.size() ; j++){
                ans |= nums[j];
                if ( ans >= k ){
                    len = min(len,j-i+1);
                }
            }
            
        }
        return len == INT_MAX ? -1 : len;
    }
};