class Solution {
public:
    bool hasAllCodes(string s, int k) { // T.C.=O(n), S.C.=O(2^k)
        if(s.length() < k)
            return false;
        unordered_set<string> st;
        int total = 1 << k; // 2^k 
        for(int i=0; i <= s.length() - k; i++)
        {
            string curr = s.substr(i, k);
            st.insert(curr);
            if(st.size() == total)
                return true;
        }
        return false;
    }
};