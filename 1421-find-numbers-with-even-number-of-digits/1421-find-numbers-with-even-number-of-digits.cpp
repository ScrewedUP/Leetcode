class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cntT = 0;
        for(int i = 0 ; i < n ; i++){
            auto cnt = [&](int x){
                int j = 0;
                while(x > 0){
                    j++;
                    x /= 10;
                }
                return j;
            };
            if ( cnt(nums[i]) % 2 == 0 ){
                cntT++;
            }
        }
        return cntT;
    }
};