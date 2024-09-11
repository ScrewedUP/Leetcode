class Solution {
public:
    bool check(int d,vector<int> &nums){
        int i = 0;
        int j = d;
        while ( j < nums.size()){
            if ( nums[i] <= nums[j]){
                return true;
            }
            i++;j++;
        }
        return false;
    }
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        for(int i = nums.size(); i >= 1 ; i--){
            if ( check(i,nums) ) return i;
        }
        return ans;
    }
};