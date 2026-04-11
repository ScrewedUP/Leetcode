class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }

        for(auto it : m){
            int sz = it.second.size();
            if ( sz < 3 ) continue;

            int i = 0;
            int j = i + 1;
            int k = j + 1;
            while ( k < sz){
                ans = min(ans,abs(it.second[i] - it.second[j])+abs(it.second[k] - it.second[j])+abs(it.second[i] - it.second[k]));
                i++;j++;k++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};