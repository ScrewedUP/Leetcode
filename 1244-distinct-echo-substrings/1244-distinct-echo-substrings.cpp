class Solution {
public:
    int distinctEchoSubstrings(std::string s){
        using ull = unsigned long long;
        int n = s.size();
        const ull B = 1315423911ULL;
        std::vector<ull> p(n+1), pref(n+1);
        p[0]=1;
        for(int i=0;i<n;i++){
            p[i+1]=p[i]*B;
            pref[i+1]=pref[i]*B + (unsigned char)s[i] + 1;
        }
        auto get = [&](int l,int len)->ull{
            return pref[l+len] - pref[l]*p[len];
        };
        std::unordered_set<ull> st;
        int cnt = 0;
        for(int L=2; L<=n; L+=2){
            int h = L/2;
            for(int i=0;i+L<=n;i++){
                if (get(i,h) == get(i+h,h)){
                    ull whole = get(i,L);
                    ull key = whole ^ ( (ull)L<<32 );
                    if (st.insert(key).second) cnt++;
                }
            }
        }
        return cnt;
    }
};
