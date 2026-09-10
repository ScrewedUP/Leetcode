class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            if ( i == 0 ){
                nums[i] = 1;
            }
            else{
                if ( nums[i] - nums[i-1] > 1){
                    nums[i] = nums[i-1] + 1;
                }
            }
        }
        for(auto i : nums) cout << i << " ";
        return *max_element(nums.begin(),nums.end());

    }
};