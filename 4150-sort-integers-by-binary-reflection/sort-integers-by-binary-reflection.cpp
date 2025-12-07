class Solution {
public:
    int Get(int x){
        bool ok = false;
        int a = 0;
        string ans;
        for(int i = 31 ; i >= 0 ; i--){
            if ( x&(1<<i) ){
                ok = true;
                ans += '1';
            }
            else{
                if ( ok ){
                    a |= ( 1<<i);
                    ans += '0';
                }
            }
        }
        reverse(ans.begin(),ans.end());
        
        int n = ans.size();
        a = stoi(ans, nullptr, 2); 
        // cout << ans << " " << a << endl;
        return a;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            int c = nums[i];
            int x = Get(c);
            ans.push_back({x,c});
        }
        sort(ans.begin(),ans.end());
        vector<int> an;
        for(int i  = 0 ; i < ans.size() ; i++){
            an.push_back(ans[i].second);
        }
        return an;
        
    }
};