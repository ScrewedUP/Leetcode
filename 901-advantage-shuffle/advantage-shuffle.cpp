class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> m;
        for (auto it : nums1) m.insert(it);

        vector<int> ans;
        int n = nums2.size();

        for (int i = 0; i < n; i++) {
            auto it = m.upper_bound(nums2[i]);

            if (it != m.end()) {
                ans.push_back(*it);
                m.erase(it);
            } else {
                auto it2 = m.begin();
                ans.push_back(*it2);
                m.erase(it2);
            }
        }
        return ans;
    }
};
