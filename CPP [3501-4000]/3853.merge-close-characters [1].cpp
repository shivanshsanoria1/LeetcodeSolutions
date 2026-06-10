class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    string mergeCharacters(string s, int k) {
        vector<int> prevIdx(26, -1);
        string ans = "";
        for(const char ch: s){
            const int currIdx = ans.length();
            if(prevIdx[ch - 'a'] == -1 || currIdx - prevIdx[ch - 'a'] > k){
                prevIdx[ch - 'a'] = currIdx;
                ans.push_back(ch);
            }
        }

        return ans;
    }
};