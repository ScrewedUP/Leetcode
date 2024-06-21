class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int left = 0;
        int sum = 0;
        int currSum = 0;
        for(int right = 0 ; right < n ;right++ ){
            if ( grumpy[right] == 1 ){
                currSum += customers[right];
            }
            while(right - left + 1 > minutes){
                if ( grumpy[left] == 1 ){
                    currSum -= customers[left];
                }
                left++;
            }
            sum = max(sum,currSum);
        }
        for(int i = 0 ; i < n ; i++){
            if ( grumpy[i] == 0 ){
                sum += customers[i];
            }
        }
        return sum;
    }
};