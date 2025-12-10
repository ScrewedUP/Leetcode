class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n = nums.size();
       vector<pair<int,int>> vp;
       for(int i = 0 ; i < n ; i++){
        int c = nums[i];
        int sum = 0;
        while ( c > 0){
            int x = c % 10;
            c/=10;
            sum += x;
        }
        vp.push_back({sum,nums[i]});
       }
       sort(vp.begin(), vp.end());
    //    for(auto it : vp) cout << it.second << " ";
    //    cout << endl;
       map<int,int> m1,m2;
       for(int i = 0 ; i < n ; i++){
            m1[nums[i]] = i;
            m2[vp[i].second] = i;
       }
       int cnt = 0;
       for(auto it : m2){
            int idx = it.second;
            int val = it.first;
            // cout << val << " " << idx << endl;
            if ( m1[val] != idx){
                cnt++;
                int newIdx = m1[val];
                int t = vp[newIdx].second;
                swap(vp[idx],vp[newIdx]);
                m2[t] = idx;
                m2[val] = newIdx;
            }
       }
       return cnt;
    }
};