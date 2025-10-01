class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int done = numBottles;
        int empty = numBottles;
        while ( empty >= numExchange){
            done += empty/numExchange;
            empty = empty/numExchange + empty%numExchange;
        }
        return done;
    }
};