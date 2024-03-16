class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> m;
        m[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] == 1 ) sum++;
            else sum--;
            if ( m.find(sum) != m.end()){
                ans = max(ans,i - m[sum]);
            }
            else m[sum] = i;
        }
        return ans;
    }
};