class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string minRemoveToMakeValid(string s) {
        // indexes of the invalid left and right parenthesis respectively
        vector<int> invalidLefts;
        vector<int> invalidRights;

        for(int i=0; i<s.length(); i++)
        {
            // assume left-parenthesis are invalid until
            // their matching right-parenthesis is found
            if(s[i] == '(')
                invalidLefts.push_back(i);
            else if(s[i] == ')')
            {
                // matching left-parenthesis found,
                // so right-parenthesis is valid
                if(!invalidLefts.empty())
                    invalidLefts.pop_back();
                // no matching left-parenthesis found, 
                // so right-parenthesis is invalid
                else
                    invalidRights.push_back(i);
            }
        }

        // build the valid string but skipping the chars with
        // index found in invalidLefts[] or invalidRights[]
        string validStr = "";
        int leftIdx = 0, rightIdx = 0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(' && leftIdx < invalidLefts.size() && i == invalidLefts[leftIdx])
            {
                leftIdx++;
                continue;
            }
            else if(s[i] == ')' && rightIdx < invalidRights.size() && i == invalidRights[rightIdx])
            {
                rightIdx++;
                continue;
            }

            validStr += s[i];
        }

        return validStr;
    }
};
/*
# assume the left-parenthesis are invalid until their 
  matching right-parenthesis is found
# right-parenthesis is invalid if its matching 
  left-parenthesis is not found
*/