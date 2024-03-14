class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       map<int,int> m;
       m[0] = 1;
       int sum = 0;
       int ans = 0;
       for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            int req = sum - goal;
            if ( m.find(req) != m.end() ) ans += m[req];
            m[sum]++;
        }
        // for(auto it : m ) cout << it.first << " " << it.second << endl;
        return ans; 
    }
};