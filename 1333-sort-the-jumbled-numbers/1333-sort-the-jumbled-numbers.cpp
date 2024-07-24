class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int> m;
        for(int i = 0 ; i < mapping.size() ; i++){
            m[i] = mapping[i];
        }
        map<int,int> mp;
        for(int i = 0 ;i < nums.size() ; i++){
            int curr = nums[i];
            string currNum = to_string(curr);
            for(int j = 0 ; j < currNum.size() ; j++){
                if ( m.find(currNum[j] - '0') != m.end()){
                    int ch = m[currNum[j] - '0'];
                    currNum[j] = ch + '0';
                }
            }
            int x = 0;
            while ( currNum[x] == '0'){
                x++;
            }
            if ( x > 0 && x < currNum.size()){
                string newStr = "";
                for(int k = x ; k < currNum.size() ; k++){
                    newStr += currNum[k];
                }
                int ny = stoi(newStr);
                mp[nums[i]] = ny;
            }
            else{
                int ny = stoi(currNum);
                mp[nums[i]] = ny;
            }
        }
        sort(nums.begin(),nums.end(),[&mp](int &a, int &b){
            return mp[a] < mp[b];
        });
        return nums;
    }
};