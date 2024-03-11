class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        map<string,int> m;
        for(auto str : arr) {
            int n = str.size();
            set<string> s;
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j <= n; j++) {
                    string sub = str.substr(i, j - i);
                    s.insert(sub);
                }
            }
            for(auto it : s){
                m[it]++;
            }
        }
        
        vector<string> ans;
        for(auto it : arr ){
            string ans1 = "";
            for(int i = 0 ; i < it.size() ; i++){
                for(int j = i+1 ; j <= it.size() ; j++){
                    string curr = it.substr(i,j-i);
                    if ( m.find(curr) != m.end() ){
                        if ( m[curr] == 1){
                            cout << curr << " ";
                            if ( ans1.size() == 0 ) ans1 = curr;
                            else if ( curr.size() < ans1.size() ) ans1 = curr;
                            else if ( curr.size() == ans1.size()){
                                int p1 = 0;
                                int p2 = 0;
                                string newAns = curr;
                                // cout << curr << " " << ans1 << " |";
                                for(int k = 0 ; k < ans1.size() ; k++){
                                    if ( ans1[k] < curr[k]){
                                        
                                        break;
                                    }
                                    else if ( ans1[k] > curr[k]){
                                        ans1 = curr;break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};