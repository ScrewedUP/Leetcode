class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        /*

            1 2 9 10

            1 + 7 + 8

            8 + 7 + 1
        */
        int n = nums.size();
        int mid = n/2;

        int ans =0 ;

        for(auto i : nums){
            ans += abs(i - nums[mid]);
        }

        return ans;
    }
};