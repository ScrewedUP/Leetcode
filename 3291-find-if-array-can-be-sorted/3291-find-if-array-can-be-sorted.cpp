class Solution {
public:
    bool isSorted(vector<int> &nums){
        for(int i = 1 ; i < nums.size() ; i++ ){
            if ( nums[i] < nums[i-1] ) return false;
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() -1 ; j++){
                if ( nums[j] > nums[j+1] ){
                    if ( __builtin_popcount(nums[j] ) == __builtin_popcount(nums[j+1]) ){
                        swap(nums[j],nums[j+1]);
                    }
                }
            }
        }
        if ( isSorted(nums)) return true;
        return false;
    }
};