class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int ans = num;
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i + 1 ; j < s.size() ; j++){
                swap(s[i],s[j]);
                int x = stoi(s);
                ans = max(ans,x);
                swap(s[i],s[j]);
            }
        }
        return ans;
    }

};