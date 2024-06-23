class Solution {
public:
    class SegmentTree{  
        int n;
        vector<int> st1,st2;

        void build(vector<int> &nums, int idx, int l, int r) {
            if (l == r) {
                st1[idx] = nums[l];
                st2[idx] = nums[l];
                return;
            }
            int mid = (l + r) / 2;
            build(nums, 2 * idx + 1, l, mid);
            build(nums, 2 * idx + 2, mid + 1, r);
            st1[idx] = max(st1[2 * idx + 1], st1[2 * idx + 2]);
            st2[idx] = min(st2[2 * idx + 1], st2[2 * idx + 2]);
        }

        int query1(int start, int end, int i, int l, int r) {
            if (start > r || end < l) return INT_MIN;
            if (start <= l && end >= r) return st1[i];
            int mid = (l + r) / 2;
            return max(query1(start, end, 2 * i + 1, l, mid), query1(start, end, 2 * i + 2, mid + 1, r));
        }

        int query2(int start, int end, int i, int l, int r) {
            if (start > r || end < l) return INT_MAX;
            if (start <= l && end >= r) return st2[i];
            int mid = (l + r) / 2;
            return min(query2(start, end, 2 * i + 1, l, mid), query2(start, end, 2 * i + 2, mid + 1, r));
        }

    public:
        SegmentTree(vector<int> &nums) {
            n = nums.size();
            st1.resize(4 * n, 0);
            st2.resize(4 * n, 0);
            build(nums, 0, 0, n - 1);
        }

        int getMax(int l, int r) {
            return query1(l, r, 0, 0, n - 1);
        }

        int getMin(int l, int r) {
            return query2(l, r, 0, 0, n - 1);
        }
    };

    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int n = nums.size();
        int maxi = 0;
        // SegmentTree st(nums);
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
