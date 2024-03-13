class Solution {
public:
    long long t[2][100005];
    long long solve(int idx,int last,vector<int> &nums){
        if ( idx >= nums.size() ) return 0;
        if ( last != -1 && t[last][idx] != -1 ) return t[last][idx];
        long long take = 0;
        if ( last == -1 || last == 0 ){
            take = nums[idx] + solve(idx+1,1,nums);
        }
        else take = -1*nums[idx] + solve(idx+1,0,nums);
        long long notTake = solve(idx+1,last,nums);
        if ( last != -1 ) t[last][idx] = max(take,notTake);
        return max(take,notTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};