class SegmentTree {
private:
    vector<int> st;
    int n;

    int build(int start, int end, int node, vector<int>& nums) {
        if (start == end) {
            st[node] = nums[start];
            return st[node];
        }
        int mid = (start + end) / 2;
        int leftChild = build(start, mid, 2 * node + 1, nums);
        int rightChild = build(mid + 1, end, 2 * node + 2, nums);
        st[node] = leftChild & rightChild;
        return st[node];
    }

    int query(int start, int end, int l, int r, int node) {
        if (r < start || l > end) {
            return INT_MAX;
        }
        if (l <= start && r >= end) {
            return st[node];
        }
        int mid = (start + end) / 2;
        int leftChild = query(start, mid, l, r, 2 * node + 1);
        int rightChild = query(mid + 1, end, l, r, 2 * node + 2);
        return leftChild & rightChild;
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n);
        build(0, n - 1, 0, nums);
    }

    int rangeAND(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree segTree(nums);
        int minDiff = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int low = i, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int currentAND = segTree.rangeAND(i, mid);

                int currentDiff = abs(k - currentAND);
                minDiff = min(minDiff, currentDiff);

                if (currentDiff == 0) {
                    return 0; 
                }

                if (currentAND < k) {
                    high = mid - 1; 
                } else {
                    low = mid + 1; 
                }
            }
        }

        return minDiff;
    }
};