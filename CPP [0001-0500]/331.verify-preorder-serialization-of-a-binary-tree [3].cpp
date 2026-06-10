class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool isValidSerialization(string preorder) {
        string curr = "";
        preorder += ",";
        int extraSpace = 1;

        for(char ch: preorder)
        {
            if(ch == ',')
            {
                // no extra space left for curr node
                if(extraSpace <= 0)
                {
                    preorder.pop_back();
                    return false;
                }

                if(curr == "#")
                    extraSpace--;
                else
                    extraSpace++;

                curr = "";
            }
            else
                curr += ch;
        }

        preorder.pop_back();
        return extraSpace == 0;
    }
};
/*
# any non-NULL node will effectively create 1-space 
  (it will first consume 1-space and then create 2-space) 
# any NULL node will just consume 1-space
# we can assume to have 1-space initially
*/