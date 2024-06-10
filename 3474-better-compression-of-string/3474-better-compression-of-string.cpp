class Solution {
public:
    string betterCompression(string compressed) {
        map<char,int> m;
        for(int i = 0 ; i < compressed.size() ; i++){
            if ( compressed[i] >= 'a' && compressed[i] <= 'z'){
                string num;
                int t = i;
                while ( i < compressed.size() - 1 && compressed[i+1] < 'a' ){
                    num += compressed[i+1];
                    i++;
                }
                int n = stoi(num);
                m[compressed[t]] += n;
                
            }
        }
        string ans;
        for(auto it : m){
            ans += it.first;
            string num = to_string(it.second);
            ans += num;
        }
        return ans;
    }
};