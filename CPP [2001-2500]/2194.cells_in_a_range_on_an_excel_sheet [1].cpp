class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c1 = s[0], c2 = s[3];
        int r1 = s[1] - '0', r2 = s[4] - '0';
        vector<string> ans;
        for(char c=c1; c<=c2; c++)
            for(int r=r1; r<=r2; r++)
                ans.push_back(c + to_string(r));
        return ans;
    }
};