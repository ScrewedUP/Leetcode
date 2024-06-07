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
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode * root = getNode();
        for(auto word : dictionary) insert(root, word);
        vector<string> s;
        string w;
        for(int i = 0 ; i < sentence.size() ; i++){
            if ( sentence[i] != ' '){
                w += sentence[i];
            }
            else{
                s.push_back(w);
                w = "";
            }
        }
        s.push_back(w);
        // for(auto it : s) cout << it << " ";
        vector<string> ans;
        for(int i = 0 ; i < s.size() ; i++){
            bool ok = true;
            TrieNode *crawler = root;
            for(int j = 0 ; j < s[i].size() ; j++){
                char ch = s[i][j];
                int idx = ch - 'a';
                if(crawler->children[idx] != NULL){
                    crawler = crawler->children[idx];
                    if ( crawler->isEnd == true){
                        ok = false;
                        ans.push_back(crawler->word);
                        break;
                    }
                }
                else{
                    break;
                }
                
            }
            if ( ok ){
                ans.push_back(s[i]);
            }
        }
        string ret;
        for(int i = 0 ; i < ans.size() ; i++){
            if ( i != ans.size() - 1){
                ret += ans[i];
                ret += ' ';
            }
            else{
                ret += ans[i];
            }
        }
        return ret;
    }
};