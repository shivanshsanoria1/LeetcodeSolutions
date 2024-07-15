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
            st.push(ch);

            if(st.size() >= 2)
            {
                char ch1 = st.top();
                st.pop();
                char ch2 = st.top();
                st.pop();

                string str = "";
                str += ch2;
                str += ch1;

                if(str == highStr)
                    points += max(x, y);
                else
                {
                    st.push(ch2);
                    st.push(ch1);
                }
            }
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
            st.push(ch);

            if(st.size() >= 2)
            {
                char ch1 = st.top();
                st.pop();
                char ch2 = st.top();
                st.pop();

                string str = "";
                str += ch2;
                str += ch1;

                if(str == lowStr)
                    points += min(x, y);
                else
                {
                    st.push(ch2);
                    st.push(ch1);
                }
            }
        }
        
        return points;
    }
};