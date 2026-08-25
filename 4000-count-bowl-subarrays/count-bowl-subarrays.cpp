class Solution {
public:
    int n;
    vector<int> seg;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    /*
        Find the rightmost index in [ql, qr]
        whose value > x.
    */
    int findRightmost(int node, int l, int r,
                      int ql, int qr, int x) {

        if (r < ql || l > qr || seg[node] <= x)
            return -1;

        if (l == r)
            return l;

        int mid = (l + r) / 2;

        // Search right first because we want rightmost.
        int res = findRightmost(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr,
            x
        );

        if (res != -1)
            return res;

        return findRightmost(
            node * 2,
            l,
            mid,
            ql,
            qr,
            x
        );
    }

    /*
        Find the leftmost index in [ql, qr]
        whose value > x.
    */
    int findLeftmost(int node, int l, int r,
                     int ql, int qr, int x) {

        if (r < ql || l > qr || seg[node] <= x)
            return -1;

        if (l == r)
            return l;

        int mid = (l + r) / 2;

        // Search left first because we want leftmost.
        int res = findLeftmost(
            node * 2,
            l,
            mid,
            ql,
            qr,
            x
        );

        if (res != -1)
            return res;

        return findLeftmost(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr,
            x
        );
    }

    long long bowlSubarrays(vector<int>& nums) {
        n = nums.size();

        seg.assign(4 * n, INT_MIN);

        build(nums, 1, 0, n - 1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Nearest greater element on the left.
            int left = -1;

            if (i > 0) {
                left = findRightmost(
                    1, 0, n - 1,
                    0, i - 1,
                    nums[i]
                );
            }

            // Nearest greater element on the right.
            int right = -1;

            if (i + 1 < n) {
                right = findLeftmost(
                    1, 0, n - 1,
                    i + 1, n - 1,
                    nums[i]
                );
            }

            /*
                i is the smaller endpoint.

                If nearest greater is at distance >= 2,
                it forms a bowl with i.
            */
            if (left != -1 && i - left >= 2)
                ans++;

            if (right != -1 && right - i >= 2)
                ans++;
        }

        return ans;
    }
};