class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        /*
            cases : 
                need1 from cost1 and need2 from cost2
                need1 from cost1 and need2 from costBoth
                need1 from costBoth and need2 from cost2
                need1 from costBoth and need2 from costBoth
        */
        long long c1 = 1ll*need1*cost1 + 1ll*need2*cost2;
        long long c2 = 1ll*need2*costBoth;
        long long l2 = need1 - need2;
        if ( l2 > 0 ){
            c2 += 1ll*l2*cost1;
        }
        long long c3 = 1ll*need1*costBoth;
        long long l21 = need2 - need1;
        if ( l21 > 0 ){
            c3 += 1ll*l21*cost2;
        }
        long long c4 = 1ll*max(need1,need2)*costBoth;

        return min({c1,c2,c3,c4});
    }
};