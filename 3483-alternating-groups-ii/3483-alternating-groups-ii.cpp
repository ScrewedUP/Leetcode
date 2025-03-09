class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        int curr = 1;
        int n = colors.size();
        vector<int> temp(colors.begin(),colors.end());
        for(auto it : colors){
            temp.push_back(it);
        }
        if ( colors[0] == colors[colors.size() - 1]){
            for(int i = 1 ; i < n ; i++){
                if ( temp[i] == 1 - temp[i-1]){
                    curr++;
                    if ( curr == k ){
                        cnt++;
                        curr--;
                    }
                }
                else{
                    curr = 1;
                }
            }
        }
        else{
            for(int i = 1 ; i < n + k - 1 ; i++){
            if ( temp[i] == 1 - temp[i-1]){
                curr++;
                if ( curr == k ){
                    cnt++;
                    curr--;
                }
            }
            else{
                curr = 1;
            }
        }
        }
        
        return cnt;

    }
};