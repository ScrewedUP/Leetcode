#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define _XOPEN_SOURCE_EXTENDED 1
#include <strings.h>
#include <cstring>
typedef long long ll;
typedef vector<ll> v64;

#define fo(i, g, e) for (ll i = g; i < e; i++)
#define forn(i, e) for (ll i = 0; i < e; i++)
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define ln "\n"
#define test \
    ll t; \
    cin >> t; \
    while (t--)

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const ll M = 1e9 + 7;

struct SegTree {
    v64 tree, lazy;
    ll n;

    void init(ll _n) {
        n = _n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<int> &nums, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = nums[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(nums, v * 2, tl, tm);
            build(nums, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void push(ll v, ll tl, ll tr) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll add) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] += add;
            push(v, tl, tr);
        } else {
            ll tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        ll tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void build(vector<int> &nums) { build(nums, 1, 0, n - 1); }
    void upd(ll l, ll r, ll add) { update(1, 0, n - 1, l, r, add); }
    ll qry(ll l, ll r) { return query(1, 0, n - 1, l, r); }
};

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll n = nums.size();
        SegTree segTree;
        segTree.init(n);
        segTree.build(nums);
        for (const auto& q : queries) {
            ll l = q[0], r = q[1];
            segTree.upd(l, r, -1); 
        }
        for (ll i = 0; i < n; ++i) {
            if (segTree.qry(i, i) > 0) { 
                return false;
            }
        }

        return true;
    }
};
