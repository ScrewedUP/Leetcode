class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,int> m;
        map<int,vector<int>> d;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( m.find(nums[i]) == m.end()){
                d[nums[i]].push_back(i);
            }
            else{
                if ( d[nums[i]].size() == 1){
                    d[nums[i]].push_back(i);
                }
                else{
                    d[nums[i]].pop_back();
                    d[nums[i]].push_back(i);
                }
            }
            m[nums[i]]++;

        }
        int ans = 0;
        for(auto i : d){
            int ele = i.first;
            int cnt = m[ele];
            if ( i.second.size() == 1){
                ans++;
                continue;
            }
            

            int start = i.second[0];
            int end = i.second[1];
            if ( (end - start + 1) == cnt) ans++;
        }
        return ans;

    }
};