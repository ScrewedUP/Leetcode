class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto it : nums){
            maxOr |= it;
        }
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < (1<<n) ; i++){
            int currOr = 0;
            for(int j = 0; j < n;j++){
                if((1<<j) & i){
                    currOr |= nums[j];
                }
            }

            if ( currOr == maxOr) cnt++;
        }   
        return cnt;
    }
};