class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) { // T.C.=O(n*logn), S.C.=O(n)
        int n=names.size();
        vector<pair<int, string>> vec(n);
        for(int i=0; i<n; i++)
            vec[i] = {heights[i], names[i]};
        // sort in decreasing order of heights
        sort(vec.begin(), vec.end(), greater<pair<int, string>>()); 
        for(int i=0; i<n; i++)
            names[i] = vec[i].second;
        return names;
    }
};