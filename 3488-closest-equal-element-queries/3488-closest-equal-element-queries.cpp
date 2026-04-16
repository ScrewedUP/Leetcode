class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> m;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]].push_back(i);
        }

        /*
            here we will start to process the queries 

            for queries[0] which is 0 ans nums[0] = 1

            in map 1 -> 0,2,4

            if it is present 2 or more times then we can caluclate the minimuim

            find the index queries[i] in the vector

            take the minimum of 
                if 1st element , then the next one towards right or the back and the back
                if last , then the first one towards left and the 0th one
                if in between , the left and the right
        */
        vector<int> ans;
        for(int i : queries){
            int val = nums[i];

            if ( m[val].size() < 2 ){
                ans.push_back(-1);
                continue;
            }

            int posi = lower_bound(m[val].begin(),m[val].end(),i) - m[val].begin();
            
            /*
                this posi is the index of i in m[val]
                sor 1 -> 0 , 2 , 4

                i is 0 so posi is also 0
            */
            int minDistance = INT_MAX;
            int n = nums.size();
            if ( posi == 0 ){
                minDistance = min(minDistance,m[val][posi+1] - m[val][posi]);
                minDistance = min(minDistance,n - m[val].back() + i);
            }
            else if ( posi == m[val].size() - 1){
                minDistance = min(minDistance,m[val][posi] - m[val][posi-1]);
                minDistance = min(minDistance,n - i + m[val][0]);
            }
            else{
                minDistance = min(minDistance,m[val][posi] - m[val][posi-1]);
                minDistance = min(minDistance,m[val][posi+1] - m[val][posi]);
            }

            ans.push_back(minDistance);

        }
        return ans;

    }
};