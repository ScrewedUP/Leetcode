class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxiIdx = -1;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if ( nums[i] > maxi ){
                maxi = nums[i];
                maxiIdx = i;
            }

        }
        int secondMaxi = INT_MIN;
        for(auto it : nums){
            if ( it > secondMaxi && it < maxi ){
                secondMaxi = it;
            }
        }
        if ( maxi >= 2*secondMaxi ) return maxiIdx;
        return -1;
    }
};