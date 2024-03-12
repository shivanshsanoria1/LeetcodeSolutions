class Solution {
private:
    // if s1 and s2 are of same length:
    // returns true if s1 is lexicographically smaller than s2 and false otherwise
    // if s1 and s2 are of different length:
    // return true if s1 is of smaller length than s2 and false otherwise
    bool compareStrings(string& s1, string& s2) {
        return s1.length() == s2.length() ? s1 < s2 : s1.length() < s2.length();
    }

public:
    // T.C.=O(n*l^3), S.C.=O(n*l^2)
    // n: size of arr[], l: max length of string in arr[]
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n=arr.size();
        // substring -> { index in arr[] }
        unordered_map<string, unordered_set<int>> mp;

        // generate all substrings for each string in arr[] and
        // insert them in the map along with their respective index in arr[]
        for(int idx=0; idx<n; idx++)
            for(int i=0; i<arr[idx].length(); i++)
                for(int j=i; j<arr[idx].length(); j++)
                    mp[arr[idx].substr(i, j-i+1)].insert(idx);
        
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
                    if(mp[currSubStr].size() == 1 && (subStr == "" || compareStrings(currSubStr, subStr)))
                        subStr = currSubStr;
                }
            ans.push_back(subStr);
        }
        return ans;
    }
};