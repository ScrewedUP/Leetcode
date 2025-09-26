class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // for three sides a,b,c to be a triangle
        // a + b > c 
        // b + c > a
        // a + c > b

        // idea : from a sorted array i'll choose 2 number at index
        // i and j , then i'll binary search the index 
        sort(nums.begin(),nums.end());
        int n = nums.size(); 
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int sum = nums[i] + nums[j];
                int x = lower_bound(nums.begin(),nums.end(),sum) - nums.begin();
                x--;
                if ( x > j){
                    ans += x - j;
                }
            }
        }
        return ans;
    }
};