class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int n = fruits.size();
        map<int,int> m;
        int ans = INT_MIN;
        for(int right = 0 ;right < n ; right++){
            m[fruits[right]]++;
            while(m.size() > 2 ){
                m[fruits[left]]--;
                if ( m[fruits[left]] == 0 ) m.erase(fruits[left]);
                left++;
            }
            int sum = 0;
            for(auto it : m){
                sum += it.second;
            }
            ans = max(ans,sum); 
        }
        return ans;
    }
};