class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int n = a.size();
        int tc = 0;
        int fc = 0;
        int l = 0;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if ( a[i] == 'T') tc++;
            else fc++;

            while(min(tc,fc) > k){
                if ( a[l] == 'T') tc--;
                else fc--;
                l++;
            }
            maxi = max(maxi,i-l+1);

        }

        return maxi;
    }
};