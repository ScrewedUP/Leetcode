class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long x = 1;
        vector<int> ne;
        int z = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( nums[i] > 0 ){
                x *= nums[i];
            }
            else if ( nums[i] < 0){
                    ne.push_back(nums[i]);
                
            }
            else z++;
        }
        if ( z == nums.size()) return 0;
        sort(ne.begin(),ne.end());
        if ( z + ne.size() == nums.size()){
            if ( z == 0 && ne.size() == 1 ) return ne[0];
            if ( ne.size() == 1) return 0;
        }
        if ( ne.size() % 2 == 0){
            for(auto it : ne){
                x *= it;
            }
        }
        else{
            for(int i = 0 ; i < ne.size() -1 ; i++){
                x *= ne[i];
            }
        }
        
        return x;
    }
};