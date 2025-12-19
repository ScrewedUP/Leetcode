struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        DSU dsu(n);
        dsu.unite(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<pair<int,int>> cur;
            vector<int> nodes;

            while (i < meetings.size() && meetings[i][2] == t) {
                int u = meetings[i][0];
                int v = meetings[i][1];
                dsu.unite(u, v);
                cur.push_back({u, v});
                nodes.push_back(u);
                nodes.push_back(v);
                i++;
            }

            for (int x : nodes) {
                if (dsu.find(x) != dsu.find(0)) {
                    dsu.p[x] = x;
                    dsu.sz[x] = 1;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(0)) ans.push_back(i);
        }
        return ans;
    }
};
