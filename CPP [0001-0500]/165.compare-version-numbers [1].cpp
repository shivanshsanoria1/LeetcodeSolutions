class Solution {
private:
    vector<int> getVersions(string& str){
        vector<int> v;
        string version = "";

        str += ".";

        for(char ch: str)
        {
            if(ch == '.')
            {
                v.push_back(stoi(version));
                version = "";
            }
            else
                version += ch;
        }

        str.pop_back();

        return v;
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVersions(version1);
        vector<int> v2 = getVersions(version2);

        int n1 = v1.size(), n2 = v2.size();
        int n = max(n1, n2);
        int i = 0, j = 0;
        
        while(n--)
        {
            int num1 = i < n1 ? v1[i] : 0;
            int num2 = j < n2 ? v2[j] : 0;

            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};