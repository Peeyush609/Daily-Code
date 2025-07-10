struct TrieNode {
    bool isEnd = false;
    TrieNode* children[26] = {nullptr};
};

class Solution {
  public:
    string longestString(vector<string> &words) {
        TrieNode* root = new TrieNode();
        
        // Insert all words into the Trie
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
        
        string ans = "";
        for (const string& word : words) {
            TrieNode* node = root;
            bool valid = true;
            
            for (int i = 0; i < word.size(); ++i) {
                int idx = word[i] - 'a';
                node = node->children[idx];
                
                // Only prefixes should exist as complete words
                if (i < word.size() - 1 && !node->isEnd) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        
        return ans;
    }
};
