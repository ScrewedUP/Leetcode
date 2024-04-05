class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        map<string,int> m;
        vector<string> ans;
        int n = folder.size();
        for(int i = 0 ; i < n ; i++){
            string curr;
            bool ok = true;
            curr += '/';
            for(int j = 1 ; j < folder[i].size() ; j++){
                while(folder[i][j] != '/' && j < folder[i].size()){
                    curr += folder[i][j];
                    j++;
                }
                if ( m.find(curr) != m.end() ){
                    cout << curr << " ";
                    ok = false;
                    break;
                }
                if ( j < folder[i].size() && folder[i][j] == '/') curr += '/';
            }
            if ( ok ){
                ans.push_back(curr);
                m[curr]++;
            }
        }
        return ans;
    }
};