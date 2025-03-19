class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] == 0){
                if ( i + 1 >= nums.size() || i + 2 >= nums.size()) return -1;
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                cnt++;
            }
        }
        return cnt;
    }
};