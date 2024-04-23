class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        q.push({"0000",0});
        map<string,bool> mp;
        for(auto &it:deadends)mp[it]=false;
        if(mp.find("0000")!=mp.end())return -1;
        mp["0000"]=false;
        while(!q.empty()){
            auto s=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(s==target)return cnt;
            for(int i=0;i<8;i++){
                string t=s;
                if(i<4){
                    if(t[i%4]!='9')t[i%4]=t[i%4]+1;
                    else t[i%4]='0';
                    if(mp.find(t)==mp.end()){
                        mp[t]=false;
                        q.push({t,cnt+1});
                    }
                }else{
                    if(t[i%4]!='0')t[i%4]=t[i%4]-1;
                    else t[i%4]='9';
                    if(mp.find(t)==mp.end()){
                        mp[t]=false;
                        q.push({t,cnt+1});
                    }
                }
            }
            
        }
        return -1;
    }
};