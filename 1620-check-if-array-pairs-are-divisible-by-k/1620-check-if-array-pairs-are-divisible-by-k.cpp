class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            arr[i] %= k;
            if (arr[i] < 0) {
                arr[i] += k;
            }
        }
        
        multiset<int> s(arr.begin(), arr.end());
        
        while (!s.empty()) {
            auto it = s.begin();
            int x = *it;
            s.erase(it);
            
            int c = (k - x) % k;
            
            if (c == 0) {
                auto zeroIt = s.find(0);
                if (zeroIt == s.end()) return false;
                s.erase(zeroIt);
            } else {
                auto cIt = s.find(c);
                if (cIt == s.end()) return false;
                s.erase(cIt);
            }
        }
        
        return true;
    }
};