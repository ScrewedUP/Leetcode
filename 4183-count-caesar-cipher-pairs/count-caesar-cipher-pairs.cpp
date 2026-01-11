class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> m;
        long long ans = 0;
        for(int i = 0 ; i < words.size() ; i++){
            string temp;
            int diff = 26 - (words[i][0]-'a');
            for(int j = 0 ; j < words[i].size() ; j++){
                int x = words[i][j] - 'a';
                int y = (x + diff)%26;
                temp += (y + 'a');
            }
            m[temp]++;
        }
        for(auto it : m){
            ans += 1ll*( it.second - 1)*1ll*(it.second)/2;
        }
        return ans;
    }
};