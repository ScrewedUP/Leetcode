class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> x;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int c =  nums[i];
            int sum =0;
            while ( c > 0){
                sum += c % 10;
                c/=10;
            }
            x.push_back(sum);
        }
        map<int,vector<int>> m;
        for(int i = 0 ; i < n ; i++){
            m[x[i]].push_back(nums[i]);
        }
        int maxi = -1;
        for(auto it : m){
            if ( it.second.size() > 1){
                sort(it.second.rbegin(),it.second.rend());
                maxi = max(maxi,it.second[0]+it.second[1]);
            }
            
        }
        return maxi;
    }
};