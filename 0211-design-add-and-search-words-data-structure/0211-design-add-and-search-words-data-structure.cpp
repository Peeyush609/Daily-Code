struct Node {
    Node* links[26];
    bool flag = false;

    // get
    Node* get(char c) { return links[c - 'a']; }

    // put
    void put(char c) { links[c - 'a'] = new Node(); }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class WordDictionary {
private:
    Node* root;
    bool solve(string word, Node* curr, int i) {
        int n = word.size();

        if (i == n)
            return curr->isEnd();

        if (word[i] == '.') {
            for (char c = 'a'; c <= 'z'; c++) {
                if(curr->get(c)){
                    if (solve(word, curr->get(c), i + 1)){
                        return true;
                    }
                }
            }
            return false;
        }

        if(!curr->get(word[i]))   return false;

        return solve(word, curr->get(word[i]), i + 1);
    }

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->get(c))
                curr->put(c);
            curr = curr->get(c);
        }

        curr->setEnd();
    }

    bool search(string word) { return solve(word, root, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */