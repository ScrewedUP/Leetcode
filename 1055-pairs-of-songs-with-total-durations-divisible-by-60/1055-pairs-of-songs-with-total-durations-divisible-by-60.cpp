class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i = 0 ; i< time.size() ; i++){
            time[i] %= 60;
        }
        map<int,int> m;
        // m[0] = 1;
        int cnt = 0;
        for(int i = 0 ; i < time.size() ; i++){
            int curr = time[i];
            int rem = (60 - time[i])%60;
            if ( m.find(rem) != m.end()){
                cnt += m[rem];
            }
            m[curr]++;
        }
        return cnt;
    }
};