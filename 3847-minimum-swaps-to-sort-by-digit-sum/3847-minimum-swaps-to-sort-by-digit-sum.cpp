class Solution {
public:
    int ceil(int x, int y) {
        if (x % y == 0) {
            return x / y;
        }
        return x / y + 1;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long,int>> v;
        vector<int> sv;
        for(int i = 0 ; i < n ; i++){
            int x = nums[i];
            int y = x;
            long long sum = 0;
            while ( x > 0){
                sum += x%10;
                x/=10;
            }
            v.push_back({sum,y});
        }
        sort(v.begin(),v.end());
        for(auto it : v){
            sv.push_back(it.second);
        }
        int cnt = 0;
        map<int,int> m2;
        for(int i = 0 ; i < n ; i++){
            m2[sv[i]] = i;
        }
        map<int,pair<int,int>> m;
        for(int i = 0 ; i < n ; i++){
            int idx = m2[nums[i]];
            m[nums[i]] = {i,idx};
        }
        for(auto it : m){
            if ( it.second.first != it.second.second){
                int val = nums[it.second.second];
                swap(nums[it.second.first],nums[it.second.second]);
                int x = m[val].second;
                m[val] = {it.second.first,x};
                m[it.first] = {it.second.second,it.second.second};
                cnt++;
            }
        }
        return cnt;
    }
};

/*
    [277993448,416038674,616955867,539372283]
    [416038674 539372283 277993448 616955867]
    1 + 
    277993448 -> {0,2} -> {2,2}
    416038674 -> {1,0} -> {0,0}
    616955867 -> {2,3} -> {1,3}
    539372283 -> {3,1} -> 
*/