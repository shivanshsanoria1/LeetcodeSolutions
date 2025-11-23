class TrieNode{
public:
    vector<TrieNode*> children;
    bool end = false;

    TrieNode(){
        this->children.resize(26, nullptr);
        this->end = false;
    }
};

class WordDictionary {
private:
    TrieNode* root = nullptr;

    bool dfs(string& word, int i, TrieNode* curr){
        if(i == word.length())
            return curr->end;

        char ch = word[i];

        if(ch == '.')
        {
            for(int j=0; j<26; j++)
            {
                if(curr->children[j] == nullptr)
                    continue;
                if(dfs(word, i+1, curr->children[j]))
                    return true;
            }
            return false;
        }
        
        int j = ch - 'a';

        if(curr->children[j] == nullptr)
            return false;
        
        return dfs(word, i+1, curr->children[j]);
    }

public:
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(word, 0, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */