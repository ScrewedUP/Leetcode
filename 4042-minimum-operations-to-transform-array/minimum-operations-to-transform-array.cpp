class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int close = INT_MAX;
        int n = nums1.size();
        for(int i = 0 ; i < n ; i++){
            int f = nums1[i];
            int s = nums2[i];
            close = min(close,abs(nums1[i] - nums2.back()));
            if ( s == f ){
                continue;
            }
            else if ( s < f ){
                if ( nums2.back() >= s && nums2.back() <= f){
                    close = 0;
                }
                ans += abs(s-f);
                close = min(close,abs(s-nums2.back()));
                close = min(close,abs(f-nums2.back()));
            }
            else{
                if ( nums2.back() >= f && nums2.back() <= s){
                    close = 0;
                }
                ans += abs(s-f);
                close = min(close,abs(s-nums2.back()));
                close = min(close,abs(f-nums2.back()));
            }
        }
        ans += (close + 1);
        return ans;
    }
};