class Solution {
public:

    struct SegmentTree {
        int n;
        vector<long long> seg, lazy;

        SegmentTree(const vector<int> &a) {
            n = a.size();
            seg.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
            build(0, 0, n - 1, a);
        }

        void build(int idx, int l, int r, const vector<int> &a) {
            if (l == r) {
                seg[idx] = a[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * idx + 1, l, m, a);
            build(2 * idx + 2, m + 1, r, a);
            seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        }

        void push(int idx, int l, int r) {
            if (lazy[idx]) {
                seg[idx] -= lazy[idx] * 1LL * (r - l + 1);
                if (l != r) {
                    lazy[2 * idx + 1] += lazy[idx];
                    lazy[2 * idx + 2] += lazy[idx];
                }
                lazy[idx] = 0;
            }
        }

        void update(int idx, int l, int r, int ql, int qr, long long val) {
            push(idx, l, r);
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                lazy[idx] += val;
                push(idx, l, r);
                return;
            }
            int m = (l + r) / 2;
            update(2 * idx + 1, l, m, ql, qr, val);
            update(2 * idx + 2, m + 1, r, ql, qr, val);
            seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
        }

        long long query(int idx, int l, int r, int ql, int qr) {
            push(idx, l, r);
            if (qr < l || r < ql) return 0;
            if (ql <= l && r <= qr) return seg[idx];
            int m = (l + r) / 2;
            return query(2 * idx + 1, l, m, ql, qr) + query(2 * idx + 2, m + 1, r, ql, qr);
        }

        void subtract_range(int l, int r) {
            update(0, 0, n - 1, l, r, 1);
        }

        long long range_sum(int l, int r) {
            return query(0, 0, n - 1, l, r);
        }
    };

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        SegmentTree st(nums);
        for (auto& it : q) {
            st.subtract_range(it[0], it[1]);
        }
        for (int i = 0; i < n; ++i) {
            long long x = st.query(0, 0, n - 1, i, i);
            if (x > 0) return false;
        }
        return true;
    }
};
