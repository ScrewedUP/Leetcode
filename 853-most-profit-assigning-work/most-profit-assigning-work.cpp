class SegmentTree {
    private:
        vector<int> tree;
        int n;

        void buildTree(const vector<int>& profits, int idx, int l, int r) {
            if (l == r) {
                tree[idx] = profits[l];
            } else {
                int mid = (l + r) / 2;
                buildTree(profits, 2 * idx + 1, l, mid);
                buildTree(profits, 2 * idx + 2, mid + 1, r);
                tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
            }
        }

        int queryTree(int idx, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) {
                return 0;
            }
            if (ql <= l && qr >= r) {
                return tree[idx];
            }
            int mid = (l + r) / 2;
            return max(queryTree(2 * idx + 1, l, mid, ql, qr), queryTree(2 * idx + 2, mid + 1, r, ql, qr));
        }

    public:
        SegmentTree(const vector<int>& profits) {
            n = profits.size();
            tree.resize(4 * n, 0);
            buildTree(profits, 0, 0, n - 1);
        }

        int query(int l, int r) {
            return queryTree(0, 0, n - 1, l, r);
        }
    };
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> vp;
        for(int i = 0 ; i < n ; i++){
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end());
        vector<int> profits(n);
        for (int i = 0; i < n; i++) {
            profits[i] = vp[i].second;
        }
        SegmentTree segTree(profits);
        int ans = 0;
        for(int i = 0 ; i < worker.size() ; i++){
            int idx = upper_bound(vp.begin(), vp.end(), make_pair(worker[i], INT_MAX), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.first < b.first;
                }) - vp.begin() - 1;
            if (idx >= 0) {
                ans += segTree.query(0, idx);
            }
        }
        return ans;


    }
};