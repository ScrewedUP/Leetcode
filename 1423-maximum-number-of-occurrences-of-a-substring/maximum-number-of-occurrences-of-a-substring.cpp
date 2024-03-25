class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        map<string, int> mt;
        
        for (int i = 0; i <= s.size() - minSize; i++) {
            map<char, int> m;
            int distinct = 0;
            for (int j = i; j < i + maxSize && j < s.size(); j++) {
                m[s[j]]++;
                if (m[s[j]] == 1) {
                    distinct++;
                }
                if (distinct > maxLetters) {
                    break;
                }
                if (j - i + 1 >= minSize) {
                    mt[s.substr(i, j - i + 1)]++;
                }
            }
        }

        int maxi = 0;
        for (auto it : mt) {
            maxi = max(maxi, it.second);
        }
        return maxi;
    }
};