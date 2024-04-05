class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;
        int count = 0;

        for(char ch: s)
        {
            if(ch == '(')
            {
                count++;
                maxDepth = max(maxDepth, count);
            }
            else if(ch == ')')
                count--;
        }

        return maxDepth;
    }
};