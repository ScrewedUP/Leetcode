class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        for(auto it : tasks){
            m[it]++;
        }
        int ans = 0;
        for(auto it : m){
            int curr = it.second;
            while ( curr > 0 ){
                if ( curr % 3 == 0 ){
                    curr -= 3;
                    ans++;
                }
                else if ( curr % 2 == 0){
                    curr -= 2;
                    ans++;
                }
                else{
                    if ( curr == 1 ) return -1;
                    else{
                        curr -= 3;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};