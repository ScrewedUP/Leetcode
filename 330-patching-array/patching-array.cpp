class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt = 0;
        int left = 0;
        long long start = 1;
        while (start <= n) {
            if (left < nums.size() && nums[left] <= start){
                start += nums[left];
                left++;
            }
            else { 
                start += start;
                cnt++;
            }
        }
        return cnt;
    }
};