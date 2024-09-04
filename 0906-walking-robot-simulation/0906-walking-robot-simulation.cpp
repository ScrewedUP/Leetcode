class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        map<char,pair<char,char>> m;
        map<pair<int,int>,int> ob;
        for(auto it : o){
            ob[{it[0],it[1]}]++;
        }
        m['N'] = {'W','E'};
        m['S'] = {'E','W'};
        m['E'] = {'N','S'};
        m['W'] = {'S','N'};

        int ans = INT_MIN;
        char curr = 'N';
        int x = 0;
        int y = 0;
        for(int i = 0 ; i < c.size() ; i++){
            if ( c[i] == -1){
                curr = m[curr].second;
            }
            else if ( c[i] == -2){
                curr = m[curr].first;
            }
            else{
                for(int j = 1 ; j <= c[i] ; j++){
                    if ( curr == 'N' || curr == 'S'){
                        if ( curr == 'N'){
                            y++;
                            if ( ob.find({x,y}) != ob.end()){
                                y--;
                                break;
                            }
                            else{
                                ans = max(ans,x*x + y*y);
                            }
                            
                        }
                        else{
                            y--;
                            if ( ob.find({x,y}) != ob.end()){
                                y++;
                                break;
                            }
                            else{
                                ans = max(ans,x*x + y*y);
                            }
                        }
                    }
                    else{
                        if ( curr == 'E'){
                            x++;
                            if ( ob.find({x,y}) != ob.end()){
                                x--;
                                break;
                            }
                            else{
                                ans = max(ans,x*x + y*y);
                            }
                            
                        }
                        else{
                            x--;
                            if ( ob.find({x,y}) != ob.end()){
                                x++;
                                break;
                            }
                            else{
                                ans = max(ans,x*x + y*y);
                            }
                        }
                    }
                    
                }
                cout << x << " " << y << endl;
            }
            
        }
        return ans == INT_MIN ? 0 : ans;
    }
};