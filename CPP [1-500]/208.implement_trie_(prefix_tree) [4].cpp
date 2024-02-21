class Trie {
private:
    struct TrieNode{
        char val;
        bool end;
        TrieNode *next[26];
    };

    TrieNode* getNode(char ch){
        TrieNode* newNode = new TrieNode;
        newNode->val = ch;
        newNode->end = false;
        for(int i=0; i<26; i++)
            newNode->next[i] = NULL;
        return newNode;
    }

    TrieNode *root = NULL;

public:
    Trie() {
        root = getNode('#');
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char ch: word)
        {
            int index = ch - 'a';
            if(curr->next[index] == NULL)
                curr->next[index] = getNode(ch);
            curr = curr->next[index];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char ch: word)
        {
            int index = ch - 'a';
            if(curr->next[index] == NULL)
                return false;
            curr = curr->next[index];
        }
        return curr->end ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char ch: prefix)
        {
            int index = ch - 'a';
            if(curr->next[index] == NULL)
                return false;
            curr = curr->next[index];
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