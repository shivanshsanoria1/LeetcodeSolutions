class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Greedy
    int maximumGain(string s, int x, int y) {
        // higher-priority string
        string highStr = x > y ? "ab" : "ba";
        // lower-priority string
        string lowStr = highStr == "ab" ? "ba" : "ab";

        // Step 1: remove all occurences of higher-priority string
        // from the original string
        stack<char> st;
        int points = 0;

        for(char ch: s)
        {
            bool canPush = true;

            if(!st.empty())
            {

                string str = "";
                str += st.top();
                str += ch;

                if(str == highStr)
                {
                    points += max(x, y);
                    st.pop();
                    canPush = false;
                }
            }

            if(canPush)
                st.push(ch);
        }

        // Step 2: reconstruct the string from the chars remaining in stack
        string s2 = "";
        while(!st.empty())
        {
            s2 += st.top();
            st.pop();
        }
        reverse(s2.begin(), s2.end());

        // Step 3: remove all occurences of lower-priority string
        // from the leftover string
        for(char ch: s2)
        {
            bool canPush = true;

            if(!st.empty())
            {

                string str = "";
                str += st.top();
                str += ch;

                if(str == lowStr)
                {
                    points += min(x, y);
                    st.pop();
                    canPush = false;
                }
            }

            if(canPush)
                st.push(ch);
        }
        
        return points;
    }
};