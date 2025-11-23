class Solution {
private:
    // splits the string s by using ' ' whitespace as delimiter
    vector<string> tokenize(string& s){
        vector<string> tokens;
        string token = "";

        s += " ";
        for(char ch: s)
        {
            if(ch == ' ')
            {
                tokens.push_back(token);
                token = "";
            }
            else
                token += ch;
        }
        s.pop_back();

        return tokens;
    }

public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // fileContent -> {filePath + "/" + fileName}
        unordered_map<string, vector<string>> mp;

        for(string& path: paths)
        {
            vector<string> tokens = tokenize(path);
            string filePath = tokens[0];
            
            for(int i=1; i<tokens.size(); i++)
            {
                int t = tokens[i].length();
                int idx = tokens[i].find("(");

                string fileName = tokens[i].substr(0, idx);
                string fileContent = tokens[i].substr(idx + 1, t - idx - 2);

                mp[fileContent].push_back(filePath + "/" + fileName);
            }
        }

        vector<vector<string>> ans;
        for(auto& it: mp)
        {
            // only 1 file with this content, 
            // ie, no duplicate files
            if(it.second.size() == 1)
                continue;
                
            vector<string> temp;
            for(string& filePath_fileName: it.second)
                temp.push_back(filePath_fileName);
            
            ans.push_back(temp);
        }

        return ans;
    }
};