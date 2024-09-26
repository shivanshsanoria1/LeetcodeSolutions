class TrieNode{
public:
    vector<TrieNode*> children;
    bool end = false;

    TrieNode(){
        this->children.resize(26, nullptr);
        this->end = false;
    }
};

class Trie {
private:
    TrieNode* root = nullptr;

public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch: word)
        {
            int i = ch - 'a';

            if(curr->children[i] == nullptr)
                curr->children[i] = new TrieNode();
            
            curr = curr->children[i];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch: word)
        {
            int i = ch - 'a';

            if(curr->children[i] == nullptr)
                return false;
            
            curr = curr->children[i];
        }

        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch: prefix)
        {
            int i = ch - 'a';

            if(curr->children[i] == nullptr)
                return false;
            
            curr = curr->children[i];
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