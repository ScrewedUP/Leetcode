class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxi = 0;
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        for(int i = 2 ; i <= sqrt(100001) ; i++){
            if ( m.find(i) != m.end()){
                long long curr = i;
                int cnt = 1;
                while(m.find(curr*curr) != m.end()){
                    curr = curr*curr;
                    cnt++;
                }
                if ( cnt > 1 ){
                    maxi = max(maxi,cnt);
                }
            }
        }
        return (maxi == 0 ? -1 : maxi);
        
    }
};