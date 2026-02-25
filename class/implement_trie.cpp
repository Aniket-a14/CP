struct Node{
    Node *links[26];
    bool isEnd;
    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
        isEnd = false;
    }
};

Node *root;

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto ch : word) {
            if(temp->links[ch - 'a'] == NULL)  {
                temp->links[ch - 'a'] = new Node();
            }
            temp = temp->links[ch - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto ch : word) {
            if(temp->links[ch - 'a'] == NULL) return false;
            temp = temp->links[ch - 'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto ch : prefix) {
            if(temp->links[ch - 'a'] == NULL) return false;
            temp = temp->links[ch - 'a'];
        }
        return true;
    }
};