class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int cnt = numBottles;
        int empty = numBottles;
        while ( empty >= numExchange ){
            cnt++;
            empty -= numExchange;
            empty++;
            numExchange++;
        }
        return cnt;
    }
};