class Solution {
public:
    bool check(deque<int> &v,int target){
        int sum = 0;
        for(auto i : v){
            sum += i;
        }

        return sum <= target;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        int sum = 0;
        long long t = n;
        deque<int> dig;
        while ( t > 0){
            sum += t % 10;
            dig.push_back(t%10);
            t/=10;
        }

        if ( sum <= target) return 0;
        reverse(dig.begin(),dig.end());
        long long num = 0;
        int sz = dig.size();
        int p = 0;
        for(int i = sz - 1 ; i >= 0 ; i--){
            int rem = 10 - dig[i];
            num += pow(10,p)*rem;
            dig[i] = 0;
            if ( i > 0){
                dig[i-1] += 1;
            }
            else{
                dig.push_front(1);
            }
            p++;
            if ( check(dig,target)) return num;
        }
        return 0;
    }
};