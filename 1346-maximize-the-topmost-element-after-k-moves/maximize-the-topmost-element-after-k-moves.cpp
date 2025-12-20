class Solution {
public:
/*
    observations :
        maximum of 
            1) Remove k elements
            2) 
*/
    int maximumTop(vector<int>& nums, int k) {
        if ( nums.size() == 1 && k % 2 == 0) return nums[0];
        if ( nums.size() == 1 && k % 2 == 1) return -1;
        if ( k == 1 && nums.size() == 1 ) return -1;

        int maxi = nums[0];
        int x = nums.size();

        if ( x == k ){
            int maxi = INT_MIN;
            for(int i = 0 ; i < k - 1 ; i++ ){
                maxi = max(maxi,nums[i]);
            }
            return maxi;
        }
        else if ( x < k ){
            return *max_element(nums.begin(),nums.end());
        }
        else{
            int maxi = nums[k];
            for(int i = 0 ; i < k - 1 ; i++ ){
                maxi = max(maxi,nums[i]);
            }
            return maxi;
        }
        return -1;
    }
};