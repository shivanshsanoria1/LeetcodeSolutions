class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        vector<string> ans;
        unordered_map<string,int> mp;
        if(n<10)
            return ans;
        for(int i=0; i<n-9; i++) //find all substrings of length 10 and add them into the map
        {
            string temp=s.substr(i,10);
            mp[temp]++;
        }
        for(auto it:mp)
            if(it.second > 1)
                ans.push_back(it.first);
        return ans;
    }
};