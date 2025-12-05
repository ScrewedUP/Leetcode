class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int validCount = 0;
        int runningSum = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            runningSum += nums[i];
            if ( (sum - 2*runningSum) % 2 == 0){
                validCount++;
            }
        }
        return validCount;
    }
};