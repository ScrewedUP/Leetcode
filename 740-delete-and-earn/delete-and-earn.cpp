#define ll long long
class Solution {
public:
    int t[20001];
    int solve(int idx,vector<int> &nums,unordered_map<int,int> &m){
        if ( idx >= nums.size() ) return 0;
        if ( t[idx] != -1 ) return t[idx];
        int take = m[nums[idx]]*nums[idx];
        int notTake = solve(idx+1,nums,m);
        if ( idx + 1 < nums.size() && nums[idx] + 1 == nums[idx+1] ){
            take += solve(idx+2,nums,m);
        }
        else if ( idx + 1 < nums.size() && nums[idx] + 1 != nums[idx+1] ){
            take += solve(idx+1,nums,m);
        }
        
        return t[idx] = max(take,notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for (int i = 0;i < n; i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : m ){
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        memset(t,-1,sizeof(t));
        return solve(0,ans,m);
    }
};