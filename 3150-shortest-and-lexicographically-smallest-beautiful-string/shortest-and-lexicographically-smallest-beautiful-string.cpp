class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt = 0;
        string ans2 = "";
        deque<char> d;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;

            d.push_back(s[i]);

            while (cnt > k) {
                if (d.front() == '1')
                    cnt--;
                d.pop_front();
            }

            if (cnt == k) {
                // Remove leading zeroes
                while (!d.empty() && d.front() == '0')
                    d.pop_front();

                string temp;
                for (auto x : d)
                    temp += x;

                // First valid answer
                if (ans2.empty()) {
                    ans2 = temp;
                }
                // Shorter is better
                else if (temp.size() < ans2.size()) {
                    ans2 = temp;
                }
                // If same length, lexicographically smaller is better
                else if (temp.size() == ans2.size() && temp < ans2) {
                    ans2 = temp;
                }
            }
        }

        return ans2;
    }
};