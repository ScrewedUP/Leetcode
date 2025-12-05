class Solution {
public:
    unordered_set<string> used;
    int ans = 0;
    string s;
    int n;

    void dfs(int i) {
        if (i == n) {
            ans = max(ans, (int)used.size());
            return;
        }
        for (int j = i; j < n; j++) {
            string cur = s.substr(i, j - i + 1);
            if (used.find(cur) == used.end()) {
                used.insert(cur);
                dfs(j + 1);
                used.erase(cur); 
            }
        }
    }

    int maxUniqueSplit(string str) {
        s = str;
        n = s.size();
        ans = 0;
        dfs(0);
        return ans;
    }
};
