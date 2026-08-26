struct Node{
    Node* links[26] = {};
    bool end = false;

    set<string> vec;

    // put
    void put(char c){
        links[c - 'a'] = new Node();
    }

    bool getContains(char c){
        return links[c - 'a'] != NULL;
    }

    // get
    Node* get(char c){
        return links[c - 'a'];
    }

    // setend
    void setEnd(){
        end = true;
    }

    // isend
    bool isEnd(){
        return end;
    }

};


class Solution {
private: Node* root; 
public:
    
    
    void insert(string word){
        Node* curr = root;
        for(char c: word){
            if(!curr->getContains(c)){
                curr->put(c);
            }
            curr = curr->get(c);
            curr->vec.insert(word);
        }

        curr->setEnd();
    }

    vector<string> search(string pre){
        Node* curr = root;
        for(char c: pre){
            if(!curr->getContains(c)){
                return {};
            }
            
            curr = curr->get(c);
        }

        vector<string> ans;
        int cnt = 0;
        for(auto s: curr->vec){
            ans.push_back(s);
            cnt++;
            if(cnt == 3)    break;
        }
        return ans;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        int m = searchWord.size();

        vector<vector<string>> ans;
        root = new Node();
        for(auto product: products){
            insert(product);
        }
        string s;
        for(int i = 0; i < m; i++){
            s += searchWord[i];
            vector<string> curr = search(s);
            ans.push_back(curr);
        }

        return ans;
    }
};