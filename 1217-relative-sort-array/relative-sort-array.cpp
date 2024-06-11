class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < arr1.size() ; j++){
                if ( arr1[j] == arr2[i] ){
                    ans.push_back(arr2[i]);
                    arr1[j] = -1;
                }
            }
        }
        vector<int> temp;
        for(int i = 0 ; i < arr1.size() ; i++){
            if ( arr1[i] != -1 ) temp.push_back(arr1[i]);
        }
        sort(temp.begin(),temp.end());
        for(auto ti :temp ){
            ans.push_back(ti);
        }
        return ans;
    }
};