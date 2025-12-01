class Solution {
public:
    int f(vector<int> &nums,int k){
        int l = 0;
        int n = nums.size();
        int cnt = 0;
        map<int,int> m;
        for(int i = 0 ; i < n ; i++){
            m[nums[i]]++;
            while(m.size() > k ){
                m[nums[l]]--;
                if ( m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            
            cnt += (i - l + 1);
            
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};