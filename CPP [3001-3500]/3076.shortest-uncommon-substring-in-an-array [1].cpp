class Solution {
private:
    // returns true if 'subStr' is a not a substring of any of the
    // strings present in arr[] (excluding the string at index 'skipIdx')
    // and false otherwise
    bool check(vector<string>& arr, int skipIdx, string& subStr) {
        for(int i=0; i<arr.size(); i++)
        {
            if(i == skipIdx)
                continue;
            // 'subStr' is a substring of arr[i]
            if(arr[i].find(subStr) != string::npos)
                return false;
        }
        return true;
    }

    // if s1 and s2 are of same length:
    // returns true if s1 is lexicographically smaller than s2 and false otherwise
    // if s1 and s2 are of different length:
    // return true if s1 is of smaller length than s2 and false otherwise
    bool compareStrings(string& s1, string& s2) {
        return s1.length() == s2.length() ? s1 < s2 : s1.length() < s2.length();
    }

public:
    // T.C.=O((n^2)*(l^3)), S.C.=O(1)
    // n: size of arr[], l: max length of string in arr[]
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans;
        for(int idx=0; idx<arr.size(); idx++)
        {
            // check for each substring of arr[idx]
            string subStr = "";
            for(int i=0; i<arr[idx].length(); i++)
                for(int j=i; j<arr[idx].length(); j++)
                {
                    // substring of arr[idx] starting at index i and ending at index j (both inclusive)
                    string currSubStr = arr[idx].substr(i, j-i+1);
                    // check if 'subStr' needs to be updated or not
                    if(check(arr, idx, currSubStr) && (subStr == "" || compareStrings(currSubStr, subStr)))
                        subStr = currSubStr;
                }
            ans.push_back(subStr);
        }
        return ans;
    }
};