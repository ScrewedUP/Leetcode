class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        int cnt = 0;
        vector<string> v;
        for(auto it : arr ){
            m[it]++;
        }
        for(auto it : arr){
            if ( m[it] == 1 ) v.push_back(it);
        }
        if ( v.size() < k ) return "";
        return v[k-1];
        
    }
};