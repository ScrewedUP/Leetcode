class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long ans = INT_MIN;
        if ( nums.size() == 1 ) return nums[0]*nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            long long x = 0;
            long long y = 0;
            for(int j  = 0 ; j < nums.size() ; j++){
                if ( i != j){
                    if ( x == 0 ){
                        x = nums[j];
                    }
                    else x = gcd(x,nums[j]);
                    if ( y == 0 ){
                        y = nums[j];
                    }
                    else y = lcm(y,nums[j]);
                }
            }
            ans = max(ans,x*y);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            long long x = 0;
            long long y = 0;
            for(int j  = 0 ; j < nums.size() ; j++){
                
                    if ( x == 0 ){
                        x = nums[j];
                    }
                    else x = gcd(x,nums[j]);
                    if ( y == 0 ){
                        y = nums[j];
                    }
                    else y = lcm(y,nums[j]);
                }
            
            ans = max(ans,x*y);
        }
        return ans;
    }
};