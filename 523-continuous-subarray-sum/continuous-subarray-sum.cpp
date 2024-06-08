class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int> m;
        m[0] = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            int req = sum % k;
            if ( m.find(req) == m.end() ) m[req] = i;
            else if ( i - m[req] > 1 ) return true;
        }
        return false;
    }
};