class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int distinctEchoSubstrings(string text) {
        int n=text.length();
        unordered_set<string> dict;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j += 2)
            {
                int width = j-i+1;
                if(text.substr(i, width/2) == text.substr(i + width/2, width/2))
                    dict.insert(text.substr(i, width/2));
            }
        
        return dict.size();
    }
};