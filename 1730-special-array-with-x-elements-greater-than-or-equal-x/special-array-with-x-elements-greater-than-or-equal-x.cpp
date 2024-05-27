class Solution {
public:
    int specialArray(vector<int>& nums) {
        int ans = -1;
        for(int i = 0 ; i <= 100 ; i++){
            int cnt = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if ( nums[j] >= i ) cnt++;
            }
            if ( cnt == i){
                ans = i;
                break;
            }
        }
        return ans;
    }
};