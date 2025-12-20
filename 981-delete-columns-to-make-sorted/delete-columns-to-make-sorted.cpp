class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        int col = strs[0].size();
        for(int j = 0 ; j < col ; j++){
            string s;
            for(int i = 0 ; i < strs.size() ; i++){
                s += strs[i][j];
            }
            string t = s;
            sort(t.begin(),t.end());
            if ( t != s ) cnt++;
        }
        return cnt;
    }
};