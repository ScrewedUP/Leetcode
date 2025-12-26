class Solution {
public:
    int bestClosingTime(string st) {
        int yCount = 0 ;
        for(int i = 0 ; i < st.size() ; i++){
            if ( st[i] == 'Y'){
                yCount++;
            }
        }
        int as = yCount;
        int idx = 0;

        for(int i = 0; i < st.size() ; ++i){
            st[i] == 'Y' ? yCount-- : yCount++;

            if ( yCount < as){
                idx = i+1;
                as = yCount;
            }
        }
        return idx;
    }
};