/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id,vector<int> &temp , map<int,pair<int,vector<int>>> &m){
        temp.push_back(id);
        if ( m[id].second.size() == 0 ) return;
        for(auto it : m[id].second){
            dfs(it,temp,m);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int,pair<int,vector<int>>> m;
        for(auto it : employees){
            vector<int> temp;
            for(auto it1 : it->subordinates){
                temp.push_back(it1);
            }
            m[it->id] = {it->importance,temp};
        }
        int sum = 0;
        vector<int> temp;
        dfs(id,temp,m);
        // sum += m[id].first;
        for(auto it : temp){
            sum += m[it].first;
        }
        return sum;
    }
};