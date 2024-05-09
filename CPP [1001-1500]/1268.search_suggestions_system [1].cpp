class Solution {
private:
    int comparePrefix(string& s, string& prefix){
        string str = s.substr(0, prefix.length());

        if(str < prefix)
            return 1;
        else if(str > prefix)
            return 3;
        // str == prefix
        return 2;
    }

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

            int left = 0, right = products.size() - 1;
            int idx = -1;

            while(left <= right)
            {
                int mid = left + (right - left)/2;

                if(comparePrefix(products[mid], prefix) == 2)
                {
                    idx = mid;
                    right = mid - 1;
                }
                else if(comparePrefix(products[mid], prefix) == 1)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            vector<string> suggestedWords;
            
            if(idx < products.size())
                suggestedWords.push_back(products[idx]);
            if(idx + 1 < products.size() && comparePrefix(products[idx + 1], prefix) == 2)
                suggestedWords.push_back(products[idx + 1]);
            if(idx + 2 < products.size() && comparePrefix(products[idx + 2], prefix) == 2)
                suggestedWords.push_back(products[idx + 2]);
            
            ans.push_back(suggestedWords);
        }

        return ans;
    }
};