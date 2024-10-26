class Solution {
public:
    // T.C.=O(m * n^2), S.C.=O(m)
    // n: size of folder[], m: max-length of string in folder[]
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        for(string& f1: folder)
        {
            bool include = true;
            for(string& f2: folder)
            {
                // f2 is the same as f1
                if(f1 == f2)
                    continue;
                // f2 can never be a prefix of f1 
                // if f1 is smaller in length
                if(f1.length() < f2.length())
                    continue;
                // f2 is a subfolder of f1
                if(f1.substr(0, f2.length()) == f2 && f1[f2.length()] == '/')
                {
                    include = false;
                    break;
                }
            }

            if(include)
                ans.push_back(f1);
        }


        return ans;
    }
};