class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if ( a > 0 ){
            pq.push({a,'a'});
        }
        if ( b > 0 ){
            pq.push({b,'b'});
        }
        if ( c > 0 ){
            pq.push({c,'c'});
        }
        string ans = "";
        while(!pq.empty()){
            int currCnt = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            if ( ans.size() >= 2 && ans[ans.size() - 1] == currChar && ans[ans.size() - 2] == currChar){
                if ( pq.empty()) break;
                int nextCnt = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                ans.push_back(nextChar);
                nextCnt--;
                if ( nextCnt > 0){
                    pq.push({nextCnt,nextChar});
                }
            } 
            else{
                currCnt--;
                ans.push_back(currChar);
            }
            if ( currCnt > 0 ){
                pq.push({currCnt,currChar});
            }
        }
        return ans;
    }
};