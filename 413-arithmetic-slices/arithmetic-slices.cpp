class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int diff = INT_MIN;
            for(int j = i + 2 ; j < n ; j++){
                int curr = nums[j] - nums[j-1];
                int prev = nums[j-1] - nums[j-2];
                if ( curr == prev){
                    cnt++;
                }
                else break;
            }
        }
        return cnt;
    }
};