class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        int i = 0;
        while(total - i*max(cost1,cost2) >= 0){
            long long rem = total - i*max(cost1,cost2);
            long long extra = rem/min(cost1,cost2) + 1;
            ans += extra;
            i++;
        }
        return ans;
    }
};