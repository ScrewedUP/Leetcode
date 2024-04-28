class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int,int> m;
        int ans = INT_MAX;
        for(auto it : nums2) m[it]++;
        map<int,int> m2;
        m2 = m;
        for(int i = 0 ; i < n - 2 ; i++){
            int curr = nums2[i];
            for(int j = 0 ; j < n ; j++){
                bool ok = true;
                int diff = curr - nums1[j];
                int cnt = 0;
                m2 = m;
                for(int k = 0 ; k < n ; k++){
                    if ( m2.find(nums1[k] + diff) == m2.end()){
                        cnt++;
                        if ( cnt > 2){
                            ok = false;
                            break;
                        }
                    }
                    else{
                        m2[nums1[k] + diff]--;
                        if (m2[nums1[k] + diff] == 0  ){
                            m2.erase(nums1[k] + diff);
                        }
                    }
                        
                }
                if ( ok && cnt == 2) ans = min(ans,diff);
            }
        }
        return ans;
    }
};