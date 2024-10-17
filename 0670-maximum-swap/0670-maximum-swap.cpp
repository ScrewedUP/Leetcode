class Solution {
public:
    int GetSize(int x){
        int cnt = 0;
        while(x){
            cnt++;
            x /= 10;
        }
        return cnt;
    }
    int maximumSwap(int num) {
        int sz = GetSize(num);
        string nu = to_string(num);
        string ans = nu;
        for(int i = 0 ; i < sz ; i++){
            for(int j = i+1 ; j < sz ; j++){
                swap(nu[i],nu[j]);
                ans = max(ans,nu);
                swap(nu[i],nu[j]);
            }
        }
        int ans1 = stoi(ans);
        return ans1;
    }

};