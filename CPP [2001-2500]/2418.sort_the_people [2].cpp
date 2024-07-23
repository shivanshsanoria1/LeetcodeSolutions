class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();

        // height -> name
        unordered_map<int, string> mp;
        for(int i=0; i<n; i++)
            mp[heights[i]] = names[i];
        
        // sort in decreasing order of heights
        sort(heights.begin(), heights.end(), greater<int>());

        // find the name of people with corresponding heights
        for(int i=0; i<n; i++)
            names[i] = mp[heights[i]];

        return names;
    }
};