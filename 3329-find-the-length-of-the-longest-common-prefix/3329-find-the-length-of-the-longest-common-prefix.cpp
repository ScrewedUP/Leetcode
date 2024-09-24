class Solution {
public:
    class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    int longest_common_prefix(const string& word) {
        TrieNode* node = root;
        int prefix_length = 0;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            prefix_length++;
            node = node->children[c];
        }
        return prefix_length;
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (int num : arr2) {
            trie.insert(to_string(num));
        }

        int max_prefix_length = 0;
        for (int num : arr1) {
            max_prefix_length = max(max_prefix_length, trie.longest_common_prefix(to_string(num)));
        }
        return max_prefix_length;
        }
};