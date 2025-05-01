class Solution {
public:
    unordered_map<string, int> mp;

    int solve(int i, int ans, vector<int> &v) {
        if (i == v.size()) return ans >= 0 ? ans : 1e4;

        string key = to_string(i) + "," + to_string(ans);
        if (mp.find(key) != mp.end()) return mp[key];

        int x = solve(i+1, ans + v[i], v);
        int y = solve(i+1, ans - v[i], v);

        return mp[key] = min(x, y);
    }

    int lastStoneWeightII(vector<int>& stones) {
        return solve(0, 0, stones);
    }
};
