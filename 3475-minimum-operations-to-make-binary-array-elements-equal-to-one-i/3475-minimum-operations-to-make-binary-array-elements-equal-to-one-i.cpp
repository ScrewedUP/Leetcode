class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            if ( nums[i] == 0){
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                cnt++;
            }
        }
        bool ok = true;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] == 0 ){
                ok = false;
                break;
            }
        }
        if ( ok ) return cnt;
        return -1;
    }
};