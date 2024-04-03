class Solution {
public:
struct TrieNode{
        bool isEnd;
        string word;
        TrieNode * children[26];
    };

    TrieNode * getNode(){
        TrieNode * newNode = new TrieNode();
        newNode->isEnd = false;
        newNode->word = "";
        for(int i = 0 ; i < 26 ; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode *root,string word){
        TrieNode *crawler = root;
        for(auto ch : word){
            int idx = ch - 'a';
            if ( crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
        crawler->word = word;
    }
    
    int n,m;
    vector<string> ans;
    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};
    
    void DFS(vector<vector<char>>& board,int i,int j,TrieNode*root){
        if ( i < 0 || i >= n || j < 0 || j >= m ) return;
        char ch = board[i][j];
        int idx = ch - 'a';
        
        if ( board[i][j] == '$' || root->children[idx] == NULL ) return;
        root = root->children[idx];
        if ( root->isEnd == true){
            ans.push_back(root->word);
            root->isEnd = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(pair<int, int> p:directions) {
            int new_i = i+p.first;
            int new_j = j+p.second;
            DFS(board, new_i, new_j, root);;
        }
        board[i][j] = temp;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        TrieNode * root = getNode();
        for(auto word : words) insert(root, word);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch = board[i][j];
                int idx = ch - 'a';
                if(root->children[idx] != NULL) {
                    DFS(board, i, j, root);
                }
            }
        }
        return ans;
    }
};