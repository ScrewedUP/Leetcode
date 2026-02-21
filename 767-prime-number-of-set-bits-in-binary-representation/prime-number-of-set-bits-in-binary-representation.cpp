class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        set<int> s{2,3,5,7,11,13,17,19,23,29,31};
        for(int i = left ; i <= right ; i++){
            int x = __builtin_popcount(i);
            if ( s.find(x) != s.end()){
                cnt++;
            }
        }
        return cnt;
    }
};