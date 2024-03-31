class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int exchanged = numBottles;
        numBottles = 0;
        while ( exchanged >= 0 ){
            
            if ( exchanged >= numExchange){
                exchanged -= numExchange;
                numBottles++;
                numExchange++;
            }
            else if ( numBottles > 0 ){
                ans+=numBottles;
                exchanged += numBottles;
                numBottles = 0;
                
            }
            else break;
            // cout << numBottles << " " << exchanged << " " << numExchange << endl;
        }
        return ans;
    }
};