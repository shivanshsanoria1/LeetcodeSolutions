class Solution {
public:
    // T.C.=O(n*logn + m*logn), S.C.=O(1)
    // n: size of products[], m: length of 'searchWord'
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;

        string prefix = "";

        for(char ch: searchWord)
        {
            prefix += ch;

            // index of the first string >= prefix
            int idx = lower_bound(products.begin(), products.end(), prefix) - products.begin();

            vector<string> suggestedWords;
            
            for(int i=idx; i < min((int)products.size(), idx + 3); i++)
                if(products[i].substr(0, prefix.length()) == prefix)
                    suggestedWords.push_back(products[i]);
            
            ans.push_back(suggestedWords);
        }

        return ans;
    }
};