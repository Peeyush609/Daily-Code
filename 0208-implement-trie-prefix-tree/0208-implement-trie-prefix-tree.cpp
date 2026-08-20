struct Node {
    Node* links[26];
    bool flag = false;

    bool containskey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{

private : Node* root;

public:
    Trie(){
        root = new Node();
    }

    //TC: O(length)
    void insert(string word){
        Node* node = root;
        for(char c: word){
            //if not present the insert it
            if(!node->containskey(c)){
                node->put(c, new Node());
            }
            //move to the reference trie
            node = node->get(c);
        }

        node->setEnd();
    }

    //TC: O(length)
    bool search(string word){
        Node* node = root;
        for(char c: word){
            if(! node->containskey(c)){
                return false;
            }

            node = node->get(c);
        }

        return node->isEnd();
    }

    //TC: O(length)
    bool startsWith (string prefix){
        Node* node = root;
        for(char c: prefix){
            if(! node->containskey(c)){
                return false;
            }

            node = node->get(c);
        }

        return true;
    }

};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */