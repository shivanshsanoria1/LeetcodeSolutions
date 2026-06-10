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

public:
    // T.C.=O(n), S.C.=O(n)
    bool isValidSerialization(string preorder) {
        vector<string> tokens = tokenize(preorder);

        int extraSpace = 1;

        for(string& token: tokens)
        {
            // no extra space left for curr node
            if(extraSpace <= 0)
                return false;

            if(token == "#")
                extraSpace--;
            else
                extraSpace++;
        }

        return extraSpace == 0;
    }
};
/*
# any non-NULL node will effectively create 1-space 
  (it will first consume 1-space and then create 2-space) 
# any NULL node will just consume 1-space
# we can assume to have 1-space initially
*/