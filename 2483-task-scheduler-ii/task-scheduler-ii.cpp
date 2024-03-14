class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long curr  = 0;
        map<long long ,long long> m;
        for(auto it : tasks){
            if ( m.find(it) == m.end() ){
                curr++;
                m[it] = curr;
            }
            else{
                long long last = m[it];
                if ( curr - last  > space ){
                    curr++;
                }
                else{
                    curr += space - (curr-last) + 1;
                    
                }
                m[it] = curr;
            }
        }
        return curr;
    }
};