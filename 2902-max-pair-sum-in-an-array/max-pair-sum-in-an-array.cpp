class Solution {
public:
    bool biggestDigitEqual(int x, int y){
        int maxiX = 0;
        int maxiY = 0;
        while(x > 0){
            int d = x%10;
            x/=10;
            maxiX= max(maxiX,d);
        }
        while(y > 0){
            int d = y%10;
            y/=10;
            maxiY= max(maxiY,d);
        }
        return maxiX == maxiY;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if ( biggestDigitEqual(nums[i],nums[j])){
                    ans = max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans;
    }
};