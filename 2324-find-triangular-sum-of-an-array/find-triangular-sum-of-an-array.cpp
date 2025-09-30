class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while( nums.size() > 1){
            vector<int> temp;
            int n = nums.size();
            for(int i = 0 ; i < n - 1 ; i++){
                temp.push_back((nums[i]+nums[i+1])%10);
            }
            nums = temp;
        }
        return nums[0];
    }
};