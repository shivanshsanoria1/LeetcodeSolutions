class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int left = 0, right = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] != s[left])
            {
                if(right - left + 1 >= 3)
                    ans.push_back({left, right});
                left = i;
            }
            else
                right = i;
        }
        if(right - left + 1 >= 3)
            ans.push_back({left, right});
        return ans;
    }
};