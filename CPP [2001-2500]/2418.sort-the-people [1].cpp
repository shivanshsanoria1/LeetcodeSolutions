class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) { 
        int n=names.size();

        // {height, name}
        vector<pair<int, string>> vec(n);
        for(int i=0; i<n; i++)
            vec[i] = {heights[i], names[i]};

        // sort in decreasing order of heights
        sort(vec.begin(), vec.end(), greater<pair<int, string>>()); 

        // find the name of people with corresponding heights
        for(int i=0; i<n; i++)
            names[i] = vec[i].second;
            
        return names;
    }
};