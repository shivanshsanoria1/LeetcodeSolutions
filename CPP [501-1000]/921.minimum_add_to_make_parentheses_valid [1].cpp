class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minAddToMakeValid(string s) {
        // use variable as stack to store the '(' encountered
        int stack = 0;
        int count = 0;
        for(char ch: s)
        {
            if(ch == ')')
            {
                if(stack > 0)
                    stack--;
                else
                    count++;
            }
            else
                stack++;
        }
        return stack + count;
    }
};