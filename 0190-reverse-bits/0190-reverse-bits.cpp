class Solution {
public:
    int reverseBits(int n) {
        bitset<32> b(n);
        string s = b.to_string();
        reverse(s.begin(),s.end());
        int x = stoi(s,nullptr,2);
        return x;

    }
};