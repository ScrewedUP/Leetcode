class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> e = heights;
        sort(e.begin(),e.end());
        int cnt = 0;
        for(int i  = 0 ;i < e.size() ; i++){
            if ( heights[i] != e[i] ) cnt++;
        }
        return cnt;
    }
};