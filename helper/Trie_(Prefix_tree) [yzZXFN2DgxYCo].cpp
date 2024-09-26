#include <bits/stdc++.h>
using namespace std;

// -------------------- START -------------------- //

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

// -------------------- END -------------------- //

int main() {
    vector<pair<string, string>> functionCalls = 
    { 
        {"insert", "apple"}, 
        {"search", "apple"}, 
        {"search", "app"}, 
        {"startsWith", "app"}, 
        {"insert", "app"}, 
        {"search", "app"}
    };
    
    Trie tr;
    
    for(auto& [function, parameter]: functionCalls)
    {
        if(function == "insert")
        {
            tr.insert(parameter);
            cout<<"null"<<" ";
        }
        else if(function== "search")
            cout<<tr.search(parameter)<<" ";
        else if(function == "startsWith")
            cout<<tr.startsWith(parameter)<<" ";
    }
    
    
    cout<<endl<<"-------------------"<<endl;

    return 0;
}