class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    bool isSubstringPresent(string s) {
        unordered_set<string> st;
        int n=s.length();

        for(int i=0; i<n-1; i++)
            st.insert(s.substr(i, 2));

        reverse(s.begin(), s.end());

        for(int i=0; i<n-1; i++)
            if(st.find(s.substr(i, 2)) != st.end())
                return true;

        return false;
    }
};