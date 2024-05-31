class Solution {
public:
    int first(int n){
        int cnt = 0;
        while( n ){
            if ( n & 1 == 1){
                break;
            }
            cnt++;
            n>>=1;
        }
        return cnt;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n ; i++){
            ans ^= nums[i];
        }
        int cnt = first(ans);
        int a = 0,b = 0;
        for(int i = 0 ; i < n ; i++){
            if ( nums[i] & ( 1 << cnt)) a^= nums[i];
            else b^= nums[i];
        }
        return {a,b};
    }
};