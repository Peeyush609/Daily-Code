class Node {
public:
    Node* links[26] = {};
    vector<string> suggestions;

    bool contains(char c) {
        return links[c - 'a'] != nullptr;
    }

    Node* get(char c) {
        return links[c - 'a'];
    }

    void put(char c) {
        links[c - 'a'] = new Node();
    }
};

class Solution {
public:

    Node* root = new Node();

    void insert(string& word) {
        Node* curr = root;

        for(char c : word) {

            if(!curr->contains(c)) {
                curr->put(c);
            }

            curr = curr->get(c);

            // Keep only 3 lexicographically smallest
            if(curr->suggestions.size() < 3) {
                curr->suggestions.push_back(word);
            }
        }
    }

    vector<string> search(string& prefix) {
        Node* curr = root;

        for(char c : prefix) {

            if(!curr->contains(c))
                return {};

            curr = curr->get(c);
        }

        return curr->suggestions;
    }

    vector<vector<string>> suggestedProducts(
        vector<string>& products,
        string searchWord
    ) {

        sort(products.begin(), products.end());

        for(string& product : products) {
            insert(product);
        }

        vector<vector<string>> ans;

        string prefix;

        for(char c : searchWord) {
            prefix += c;
            ans.push_back(search(prefix));
        }

        return ans;
    }
};