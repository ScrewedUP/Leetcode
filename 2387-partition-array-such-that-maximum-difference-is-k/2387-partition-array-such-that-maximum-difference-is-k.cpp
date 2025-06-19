class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int x = 1;
        int low = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if ( nums[i] - low > k){
                x++;
                low = nums[i];
            }
        }
        return x;
    }
};