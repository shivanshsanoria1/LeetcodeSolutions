class Solution {
public:
    // T.C.=O(n * m^2), S.C.=O(n*m)
    // n: size of folder[], m: max-length of string in folder[]
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s(folder.begin(), folder.end());
        vector<string> ans;

        for(string& curr: folder)
        {
            string parent = curr;
            
            while(!parent.empty())
            {
                char popped = parent.back();
                parent.pop_back();

                if(popped == '/' && s.find(parent) != s.end())
                    break;
            }

            // no parent folder found, ie, 
            // curr is not a subfolder of any other folder
            if(parent.empty())
                ans.push_back(curr);
        }

        return ans;
    }
};