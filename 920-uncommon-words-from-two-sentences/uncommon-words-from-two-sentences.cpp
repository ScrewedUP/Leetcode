class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m1,m2;
        string curr1 = "";
        string curr2 = "";
        for(int i = 0 ; i < max(s1.size(),s2.size()) ; i++){
            if ( i < s1.size() && s1[i] == ' '){
                m1[curr1]++;
                curr1 = "";
            }
            else{
                if ( i < s1.size() ) curr1 += s1[i];
            }
            if ( i < s2.size() && s2[i] == ' '){
                m2[curr2]++;
                curr2 = "";
            }
            else{
                if ( i < s2.size())
                curr2 += s2[i];
            }
        }
        m1[curr1]++;
        m2[curr2]++;
        vector<string> ans;
        for(auto it : m1){
            // cout << it.first << " " << it.second << endl;
            if ( it.second == 1 ){
                if ( m2.find(it.first) == m2.end()){
                    ans.push_back(it.first);
                }
            }
        }
        for(auto it : m2){
            if ( it.second == 1 ){
                if ( m1.find(it.first) == m1.end()){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};