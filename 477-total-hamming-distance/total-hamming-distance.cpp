class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if ( i != j) ans += __builtin_popcount(nums[i]^nums[j]);
            }
            
        }
        return ans;
    }
};