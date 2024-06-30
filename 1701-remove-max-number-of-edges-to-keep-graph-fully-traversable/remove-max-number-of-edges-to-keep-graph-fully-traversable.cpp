class DisjointSet{
    vector<int>parent,size;
    int nodes;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        nodes=n;
    }
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }
    bool unionBySize(int u,int v){
        int up=findUPar(u),vp=findUPar(v);
        if(up==vp) return 0;
        if(size[up]<size[vp]){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
        nodes--;
        return 1;
    }
    bool isConnected(){
        return nodes==1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n),bob(n);
        int cnt=0;
        for(auto x:edges){
            int t=x[0],u=x[1],v=x[2];
            if(t==3){
                cnt+=alice.unionBySize(u,v) | bob.unionBySize(u,v);
            }
        }
        for(auto x:edges){
            int t=x[0],u=x[1],v=x[2];
            if(t==1){
                cnt+=alice.unionBySize(u,v);
            }
            else if(t==2){
                cnt+=bob.unionBySize(u,v);
            }
        }
        if(alice.isConnected() && bob.isConnected()) return edges.size()-cnt;
        return -1;
    }
};