class Solution {
private:
    bool areAdjacent(char ch1, char ch2){
        return abs(ch1 - ch2) == 1 || abs(ch1 - ch2) == 25;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string resultingString(string s) {
        stack<char> st;
        for(char ch: s)
        {
            if(!st.empty() && areAdjacent(st.top(), ch))
                st.pop();
            else
                st.push(ch);
        }

        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};