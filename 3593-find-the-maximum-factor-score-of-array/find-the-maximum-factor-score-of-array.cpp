class Solution {
public:
    long long gcd(long long x, long long y)
    {
        long long r = 0, a, b;
        a = (x > y) ? x : y; 
        b = (x < y) ? x : y;

        r = b;
        while (a % b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return r;
    }
 
    long long lcm(long long x, long long y) {
        return (x / gcd(x, y)) * y;
    }
    long long maxScore(vector<int>& nums) {
        long long score = INT_MIN;
        long long g = nums[0];
        long long lc = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            g = gcd(g,nums[i]);
            lc = lcm(lc,nums[i]);
        }
        score = g*lc;
        for(int i = 0 ; i < nums.size() ; i++){
            long long currScore = INT_MIN;
            long long g = nums[0];
            long long lc = nums[0];
            int cnt = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if ( j == i ) continue;
                else if ( cnt == 0 ){
                    g = nums[j];
                    lc = nums[j];
                    cnt++;
                }
                else{
                    g = gcd(g,nums[j]);
                    lc = lcm(lc,nums[j]);
                }
            }
            currScore = g*lc;
            score = max(score,currScore);
        }
        return score;
    }
};