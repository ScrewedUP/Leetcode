class Compare {
public:
    bool operator()(vector<int> below, vector<int> above) {
        return above[0] > below[0];
    }
};

class Solution {

    bool isCyclic(vector<int>* adj, int cur, vector<bool>& dfsvis, vector<bool>& vis) {
        if(dfsvis[cur]) {
            return true;
        }

        if(vis[cur]) {
            return false;
        }
        vis[cur] = true;

        bool cyclic = false;
        dfsvis[cur] = true;
        for(int x: adj[cur]) {
            cyclic |= isCyclic(adj, x, dfsvis, vis);
        }
        dfsvis[cur] = false;

        return cyclic;
    }

    void topoSort(stack<int>& sortedElements, vector<int>* adj, int curr, vector<bool>& vis) {
        if(vis[curr]) {
            return;
        }
        vis[curr] = true;

        for(int x: adj[curr]) {
            topoSort(sortedElements, adj, x, vis);
        }
        sortedElements.push(curr + 1);
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> temp;


        vector<int> rowAdj[k];
        vector<int> rowOutDegree(k, 0);
        priority_queue<vector<int>, vector<vector<int>>, Compare> rowPQ;
        vector<bool> row1Vis(k, false);
        vector<bool> row1DfsVis(k, false);
        for(auto x: rowConditions) {
            rowAdj[x[0] - 1].push_back(x[1] - 1);
            rowOutDegree[x[0] - 1]++;
            rowOutDegree[x[1] - 1]--;
        }

        for(int i = 0; i < k; i++) {
            if(isCyclic(rowAdj, i, row1DfsVis, row1Vis)) {
                return temp;
            }
        }

        for(int i = 0; i < k; i++) {
            rowPQ.push({rowOutDegree[i], i});
        }

        vector<int> colAdj[k];
        vector<int> colOutDegree(k, 0);
        priority_queue<vector<int>, vector<vector<int>>, Compare> colPQ;
        vector<bool> col1Vis(k, false);
        vector<bool> col1DfsVis(k, false);
        for(auto x: colConditions) {
            colAdj[x[0] - 1].push_back(x[1] - 1);
            colOutDegree[x[0] - 1]++;
            colOutDegree[x[1] - 1]--;
        }

        for(int i = 0; i < k; i++) {
            if(isCyclic(colAdj, i, col1DfsVis, col1Vis)) {
                return temp;
            }
        }

        for(int i = 0; i < k; i++) {
            colPQ.push({colOutDegree[i], i});
        }

        stack<int> rowSortedElements;
        vector<bool> rowVis(k, false);
        stack<int> colSortedElements;
        vector<bool> colVis(k, false);

        while(!rowPQ.empty()) {
            int node1 = rowPQ.top()[1];
            rowPQ.pop();
            if(!rowVis[node1]) {
                topoSort(rowSortedElements, rowAdj, node1, rowVis);
            }
            int node2 = colPQ.top()[1];
            colPQ.pop();
            if(!colVis[node2]) {
                topoSort(colSortedElements, colAdj, node2, colVis);
            }
        }

        vector<int> rowOrder(k+1);
        vector<int> colOrder(k+1);
        while(!rowSortedElements.empty()) {
            rowOrder[rowSortedElements.top()] = k - rowSortedElements.size();
            rowSortedElements.pop();
            colOrder[colSortedElements.top()] = k - colSortedElements.size();
            colSortedElements.pop();
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i = 1; i <= k; i++) {
            ans[rowOrder[i]][colOrder[i]] = i;
        }

        return ans;
    }
};