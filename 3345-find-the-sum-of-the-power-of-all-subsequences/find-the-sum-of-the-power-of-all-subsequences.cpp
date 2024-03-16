class Solution {
public:
    const int M = 1e9+7;
    int t[101][101];
    int solve(int idx,int n,int k,int total,vector<int>& nums){
        if ( idx == n){
            if ( total == k ) return 1;
            return 0;
        }
        if ( t[idx][total] != -1 ) return t[idx][total];
        int count = 0;
        //take
        if ( total + nums[idx] <= k ){
            count += solve(idx+1,n,k,total + nums[idx],nums);
            count %= M;
        }
        
        count += (2*solve(idx+1,n,k,total,nums))%M;
        return t[idx][total] = count%M;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,nums.size(),k,0,nums) % M;
    }
};