class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<string> partitionString(string s) {
        unordered_set<string> segments;
        vector<string> ans;
        string curr = "";

        for(char ch: s)
        {
            curr += ch;
            // new segment found
            if(segments.find(curr) == segments.end())
            {
                segments.insert(curr);
                ans.push_back(curr);
                curr = "";
            }
        }

        return ans;
    }
};