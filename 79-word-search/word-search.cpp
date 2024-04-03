class Solution {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode * children[52];
    };

    TrieNode * getNode(){
        TrieNode * newNode = new TrieNode();
        newNode->isEnd = false;
        for(int i = 0 ; i < 52 ; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode *root,string word){
        TrieNode *crawler = root;
        for(auto ch : word){
            int idx;
            if (ch >= 'a' && ch <= 'z') {
                idx = ch - 'a';
            } else if (ch >= 'A' && ch <= 'Z') {
                idx = ch - 'A' + 26;
            } else {
                continue;
            }

            if ( crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }
    
    int n,m;
    bool ok = false;
    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
    
    bool DFS(vector<vector<char>>& board,int i,int j,TrieNode*root){
        if ( i < 0 || i >= n || j < 0 || j >= m ) return false;
        char ch = board[i][j];
        int idx;
        if (ch >= 'a' && ch <= 'z') {
            idx = ch - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            idx = ch - 'A' + 26;
        } else {
            return false;
        }
        
        if ( board[i][j] == '$' || root->children[idx] == NULL ) return false;
        root = root->children[idx];
        if ( root->isEnd == true){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(pair<int, int> p:directions) {
            int new_i = i+p.first;
            int new_j = j+p.second;
            if ( DFS(board, new_i, new_j, root) ) return true;
        }
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        TrieNode * root = getNode();
        insert(root, word);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch = board[i][j];
                int idx;
                if (ch >= 'a' && ch <= 'z') {
                    idx = ch - 'a';
                } else if (ch >= 'A' && ch <= 'Z') {
                    idx = ch - 'A' + 26;
                } else {
                    continue;
                }

                if(root->children[idx] != NULL) {
                    if (DFS(board, i, j, root)) return true;
                }
            }
        }
        return false;
    }
};