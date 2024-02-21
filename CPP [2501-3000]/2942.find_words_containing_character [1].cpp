class Solution {
public:
    // T.C.=O(n*l), S.C.=O(1), l: max length of string in words[]
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0; i<words.size(); i++)
        {
            for(char ch: words[i])
                if(ch == x)
                {
                    ans.push_back(i);
                    break;
                }
        }
        return ans;
    }
};