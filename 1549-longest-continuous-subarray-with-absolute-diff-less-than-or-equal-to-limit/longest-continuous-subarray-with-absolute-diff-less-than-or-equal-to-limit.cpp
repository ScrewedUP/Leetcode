class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int n = nums.size();
        int maxi = 0;
        multiset<int> st;
        for (int right = 0; right < n; right++) {
            st.insert(nums[right]);
            
            while (*st.rbegin() - *st.begin() > limit) {
                
                st.erase(st.find(nums[left]));
                left++;
            }
            maxi = max(maxi, right - left +  1);
            
        }

        return maxi;
    }
};
