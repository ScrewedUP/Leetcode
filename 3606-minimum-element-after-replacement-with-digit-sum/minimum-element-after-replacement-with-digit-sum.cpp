class Solution {
public:
    int GetSum(int n){
        int sum = 0;
        while( n > 0 ){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for(int i = 0 ; i < nums.size() ;i++){
            int sm = GetSum(nums[i]);
            mn = min(mn,sm);
        }
        return mn;
    }
};