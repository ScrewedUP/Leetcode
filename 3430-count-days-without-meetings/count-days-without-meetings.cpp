class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        long long cnt = 0;
        int start = 1;
        int curr = start;
        int end = 0;
        for(auto it : meetings){
            end = max(end,it[1]);
        }
        for(int i = 0 ; i < meetings.size() ; i++){
            if ( i == 0 ){
                cnt += meetings[i][0] - start;
                
            }
            else{
                if ( meetings[i][0] > meetings[i-1][1] && meetings[i][0] > curr){
                    cnt += meetings[i][0] - max(meetings[i-1][1],curr) - 1;
                }
            }
            start = min(start,meetings[i][0]);
                curr = max(curr,meetings[i][1]);
        }
        if ( days - end > 0 ){
            cnt += days - end;
        }
        return cnt;
    }
};