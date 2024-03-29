#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll count = n*1LL*(n+1)/2;
        ll i = 0, j = 0;
        int maxi = 0;
        for(auto v : nums){
            maxi = max(maxi, v);
        }
        int cnt = 0;
        while(j < n){
            if( nums[j] == maxi ){
                cnt++;
            }
            while( cnt >= k ){
                if( nums[i] == maxi ){
                    cnt -= 1;
                }
                i++;
            }
            count -= j-i+1;
            j++;
        }
        return count;
    }
};