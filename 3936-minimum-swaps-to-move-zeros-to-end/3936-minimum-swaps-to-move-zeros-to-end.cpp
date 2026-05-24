class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int j = n - 1;
        int i = 0;

        while (  i < j ){
            if ( nums[i] == 0 ){
                while (j >= 0 && nums[j] == 0 ) j--;
                if ( i < j ){
                    swap(nums[i],nums[j]);
                    cnt++;
                    j--;
                }
            }
            i++;
            
        }
        return cnt;
    }
};