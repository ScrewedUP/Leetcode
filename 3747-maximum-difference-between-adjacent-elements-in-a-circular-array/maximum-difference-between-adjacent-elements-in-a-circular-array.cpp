class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = abs(nums[0] - nums[nums.size() - 1]);
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            maxi = max(maxi,abs(nums[i] - nums[i+1]));
        }
        return maxi;
    }
};