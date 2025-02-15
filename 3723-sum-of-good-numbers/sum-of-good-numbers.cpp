class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            bool ok = true;
            if ( i >= k){
                if ( nums[i] <= nums[i-k]){
                    ok = false;
                }
            }
            if ( i + k < n ){
                if ( nums[i] <= nums[i+k]){
                    ok = false;
                }
            }
            if ( ok ){
                sum += nums[i];
            }
        }
        return sum;
    }
};