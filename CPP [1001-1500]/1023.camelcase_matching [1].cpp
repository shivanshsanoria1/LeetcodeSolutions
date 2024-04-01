class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        for(string& query: queries)
        {
            bool include = true;
            int i=0;

            for(char ch: query)
            {
                if(i < pattern.length() && ch == pattern[i])
                    i++;
                else if(isupper(ch))
                {
                    include = false;
                    break;
                }
            }

            if(i < pattern.length())
                include = false;

            ans.push_back(include);
        }

        return ans;
    }
};