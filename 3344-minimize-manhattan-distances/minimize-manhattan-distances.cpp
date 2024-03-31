class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        map<int, int> a, b;
        for (int i = 0; i < n; i++) {
            a[points[i][0] + points[i][1]]++;
            b[points[i][0] - points[i][1]]++;
        }
        int ans = max(a.rbegin()->first - a.begin()->first, b.rbegin()->first-b.begin()->first);
        for (int i = 0; i < n; i++) {
            a[points[i][0] + points[i][1]]--;
            if ( a[points[i][0] + points[i][1]] == 0 ) a.erase(points[i][0] + points[i][1]);
            b[points[i][0] - points[i][1]]--;
            if ( b[points[i][0] - points[i][1]] == 0 ) b.erase(points[i][0] - points[i][1]);
            if (!a.empty() && !b.empty()) {
                ans = min(ans, max(a.rbegin()->first - a.begin()->first, b.rbegin()->first-b.begin()->first));
            }
            a[points[i][0] + points[i][1]]++;
            b[points[i][0] - points[i][1]]++;
        }
        return ans == INT_MAX ? 0 : ans; 
    }
};