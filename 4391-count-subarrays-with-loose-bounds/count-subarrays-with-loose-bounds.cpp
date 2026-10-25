class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int l = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] >= minK && nums[i] <= maxK){
                ans += ( i - l + 1);
            }
            else{
                l = i + 1;
            }
        }

        return ans;
    }
};