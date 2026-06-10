class Solution {
private:
    // returns true if folder[j] is a subfolder of folder[i]
    bool isSubfolder(vector<string>& folder, int i, int j){
        int n1 = folder[i].length();
        int n2 = folder[j].length();

        if(n1 > n2)
            return false;

        return folder[j].substr(0, n1) == folder[i] && folder[j][n1] == '/';
    }

public:
    // T.C.=O(m*n*log(n)), S.C.=O(m)
    // n: size of folder[], m: max-length of string in folder[]
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        int n = folder.size();
        for(int i=0; i<n;)
        {
            ans.push_back(folder[i]);
            // skip the subfolders of i
            int j = i+1;
            while(j<n && isSubfolder(folder, i, j))
                j++;

            i = j;
        }

        return ans;
    }
};

// a folder is always lexicographically smaller than its subfolders