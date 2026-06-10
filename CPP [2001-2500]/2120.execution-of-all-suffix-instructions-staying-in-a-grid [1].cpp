class Solution {
public:
    // T.C.=O(m^2), S.C.=O(1)
    // m: length of s
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.length();
        vector<int> ans(m);

        for(int i=0; i<m; i++)
        {
            int x = startPos[0], y = startPos[1];
            int ins = 0; // instructions

            for(int j=i; j<m; j++)
            {
                if(s[j] == 'U')
                    x--;
                else if(s[j] == 'D')
                    x++;
                else if(s[j] == 'L')
                    y--;
                else // s[j] == 'R'
                    y++;
                
                if(x<0 || x>=n || y<0 || y>=n)
                    break;
                
                ins++;
            }

            ans[i] = ins;
        }

        return ans;
    }
};