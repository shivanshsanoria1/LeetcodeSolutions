class TrieNode{
public:
    TrieNode* children[26] = {nullptr};
    int count = 0;

    TrieNode(){
        this->count = 0;
    }
};

class Trie{
private:
    TrieNode* root = nullptr;

public:
    Trie(){
        this->root = new TrieNode();
    }

    void insert(string& word){
        TrieNode* curr = root;
        for(char ch: word)
        {
            int i = ch - 'a';

            if(curr->children[i] == nullptr)
                curr->children[i] = new TrieNode();

            curr = curr->children[i];
            curr->count++;
        }
    }

    int getPrefixCount(string& word){
        TrieNode* curr = root;
        int prefixCount = 0;
        for(char ch: word)
        {
            int i = ch - 'a';
            
            curr = curr->children[i];
            prefixCount += curr->count;
        }

        return prefixCount;
    }
};

class Solution {
public:
    // T.C.=O(n*m), S.C.=O(n*m)
    // n: size of words[], m: max-length of a word in words[]
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie tr;
        for(string& word: words)
            tr.insert(word);
        
        vector<int> scores;
        for(string& word: words)
            scores.push_back(tr.getPrefixCount(word));

        return scores;
    }
};

// NOTE: use array instead vector in TrieNode to avoid MLE