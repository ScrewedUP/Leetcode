class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        /*
            n1 = [2, 4,  5,  30, 55]
            n2 = [100, 20, 10, 10, 5]

            max(j-i)
        */
        int ans = INT_MIN;
        for(int i = 0 ; i < nums2.size() ; i++){
            int idx = lower_bound(nums1.begin(),nums1.end(),nums2[i],greater<int>()) - nums1.begin();

            if ( idx <= i && idx < nums1.size()){
                ans = max(ans,i - idx);
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};