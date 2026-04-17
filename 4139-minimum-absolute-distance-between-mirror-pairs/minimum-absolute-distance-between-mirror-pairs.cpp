class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i = 0 ;i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        int mini = INT_MAX;
        for(int i = 0 ;i < nums.size(); i++){
            int x = nums[i];
            string a = to_string(nums[i]);
            reverse(a.begin(),a.end());
            string b;
            bool ok = false;
            for(int j = 0 ; j < a.size() ; j++){
                if ( !ok && a[j] == '0'){
                    
                }
                else{
                    b.push_back(a[j]);
                    ok = true;
                }
            }
            int nx = 0;
            if ( b.length() > 0 ){
                nx = stoi(b);
            }
            if ( m.find(nx) != m.end()){
                
                int x = upper_bound(m[nx].begin(),m[nx].end(),i) - m[nx].begin();
                int idx = -1;
                if ( x < m[nx].size()) idx = m[nx][x];
                // cout << i << " " << idx << endl;
                if ( idx != -1 && i!=idx )mini = min(mini,abs(i-idx));
            }
            
        }
        return mini == INT_MAX ? -1 : mini;
    }
};