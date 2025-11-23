class Solution {
private:
    vector<string> tokenize(string& preorder){
        vector<string> tokens;
        string token = "";
        preorder += ",";

        for(char ch: preorder)
        {
            if(ch == ',')
            {
                tokens.push_back(token);
                token = "";
            }
            else
                token += ch;
        }

        preorder.pop_back();
        return tokens;
    }

    bool dfs(vector<string>& tokens, int& i){
        if(i >= tokens.size())
            return false;

        if(tokens[i] == "#")
            return true;
        
        return dfs(tokens, ++i) && dfs(tokens, ++i);
    }

public:
    // T.C.=O(n), S.C.=O(n)
    bool isValidSerialization(string preorder) {
        vector<string> tokens = tokenize(preorder);
        int i = 0;

        dfs(tokens, i);
        
        return i == tokens.size() - 1;
    }
};