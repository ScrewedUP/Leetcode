struct TrieNode{
    TrieNode* children[10];
};
class Solution {
public:
    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode();

        for(int i = 0 ; i < 10 ; i++){
            node->children[i] = nullptr;
        }

        return node;
    }

    void insert(int num,TrieNode* root){
        TrieNode* crawler = root;

        string numStr = to_string(num);

        for(auto d : numStr){
            int idx = d - '0';

            if ( !crawler->children[idx]){
                crawler->children[idx] = getTrieNode();
            }

            crawler = crawler->children[idx];
        }
    }
    int search(int num,TrieNode* root){
        TrieNode* crawler = root;

        string numStr = to_string(num);

        int length = 0;

        for(auto d : numStr){
            int idx = d - '0';

            if ( crawler->children[idx]){
                length++;
                crawler = crawler->children[idx];
            }
            else break;
        }

        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        TrieNode* root = getTrieNode();

        for(auto i : arr1){
            insert(i,root);
        }

        int ans = 0;

        for(auto i : arr2){
            ans = max(ans,search(i,root));
        }
        
        return ans;
    }
};