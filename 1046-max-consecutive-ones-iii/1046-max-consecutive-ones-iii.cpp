class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zc = 0;
        int n = nums.size();
        int maxi = 0;
        for(int r = 0 ; r < n ; r++){
            if ( nums[r] == 0 ){
                zc++;
            }
            while(zc > k){
                if ( nums[l] == 0){
                    zc--;
                }
                l++;
            }
            maxi = max(maxi,(r-l+1));
        }
        return maxi;
    }
};