class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = ( nums[0] == target ? 1 : 0);

        for(int i = 1 ; i < n ; i++){
            pre[i] = pre[i-1] + ( nums[i] == target ? 1 : 0);
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int l = j - i + 1;

                if ( pre[j] - (i > 0 ? pre[i-1] : 0) > l/2) cnt++;
            }
        }
        return cnt;
    }
};