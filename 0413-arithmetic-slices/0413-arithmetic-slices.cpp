class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int diff = INT_MIN;
            for(int j = i + 1 ; j < n ; j++){
                if ( diff == INT_MIN){
                    diff = nums[j] - nums[j-1];
                }
                else{
                    int curr = nums[j] - nums[j-1];
                    if ( curr == diff){
                        cnt++;
                    }
                    else break;
                }
            }
        }
        return cnt;
    }
};