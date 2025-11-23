class Solution {
public:
    // T.C.=O(n*l*logl), S.C.=O(n)
    // n: legnth of strs[], l: max length of string in strs[]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sorted string -> {anagrams of that string found in strs[]}
        unordered_map<string, vector<string>> mp;
        for(string& str: strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it: mp)
            ans.push_back(it.second);
        return ans;
    }
};