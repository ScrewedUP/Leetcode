class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneCnt = 0;
        int zeroCnt = 0;
        for(int i = 0 ; i < students.size() ; i++){
            if ( students[i] == 1 ) oneCnt++;
            else zeroCnt++;
        }
        for(int i = 0 ; i < sandwiches.size() ; i++){
            if ( sandwiches[i] == 1 ){
                if ( oneCnt == 0 ) return zeroCnt;
                else oneCnt--;
            }
            else{
                if ( zeroCnt == 0 ) return oneCnt;
                else zeroCnt--;
            }
        }
        return max(oneCnt,zeroCnt);
    }
};