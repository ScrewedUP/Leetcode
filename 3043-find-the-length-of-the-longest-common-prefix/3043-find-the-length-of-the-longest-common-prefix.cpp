class Trie {
    struct Node {
        Node* child[10];

        Node() {
            for (int i = 0; i < 10; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* curr = root;

        string s = to_string(num);

        for (char c : s) {
            int digit = c - '0';

            if (curr->child[digit] == nullptr) {
                curr->child[digit] = new Node();
            }

            curr = curr->child[digit];
        }
    }

    int getLCP(int num) {
        Node* curr = root;
        string s = to_string(num);

        int len = 0;

        for (char c : s) {
            int digit = c - '0';

            if (curr->child[digit] == nullptr)
                break;

            curr = curr->child[digit];
            len++;
        }

        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;

        for(auto i : arr2){
            t.insert(i);
        }

        int ans = 0;

        for(auto i : arr1){
            ans = max(ans,t.getLCP(i));
        }

        return ans;
    }
};