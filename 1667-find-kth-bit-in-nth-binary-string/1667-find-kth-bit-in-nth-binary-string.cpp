class Solution {
public:
    string invert(string ans ){
        for(int i = 0 ; i < ans.size() ; i++){
            if ( ans[i] == '0'){
                ans[i] = '1';
            }
            else{
                ans[i] = '0';
            }
        }
        return ans;
    }

    char findKthBit(int n, int k) {
        string ans = "0";
        for(int i = 0 ; i < n; i++){
            string temp = invert(ans);
            reverse(temp.begin(),temp.end());
            ans += '1';
            ans += temp;
        }
        // cout << ans << " ";
        return ans[k-1];
    }
};