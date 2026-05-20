class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,int> m;
        int cnt = 0;
        for(int i = 0 ; i < A.size() ; i++){
            m[A[i]]++;
            m[B[i]]++;

            if ( m[A[i]] > 1) cnt++;
            if ( A[i] != B[i] && m[B[i]] > 1 ) cnt++;

            ans.push_back(cnt);
        }
        return ans;
    }
};