class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string pushDominoes(string dominoes) {
        // adding a 'L' at starting and 'R' at end 
        // does not affect the final configuration of dominoes
        string str = "L" + dominoes + 'R';
        string ans = "";

        for(int curr = 1, prev = 0; curr < str.length(); curr++)
        {
            if(str[curr] == '.')
                continue;
            
            // size of window of '.'s
            // '.'s are in index-range [prev+1, curr-1]
            // size = (curr-1) - (prev+1) +1
            int sz = curr - prev - 1;

            if(str[prev] == 'L' && str[curr] == 'L')
                ans += string(sz, 'L');
            else if(str[prev] == 'R' && str[curr] == 'R')
                ans += string(sz, 'R');
            else if(str[prev] == 'L' && str[curr] == 'R')
                ans += string(sz, '.');
            else if(str[prev] == 'R' && str[curr] == 'L')
            {
                ans += string(sz/2, 'R');
                if(sz % 2 == 1)
                    ans += ".";
                ans += string(sz/2, 'L');
            }
            
            ans += str[curr];
            prev = curr;
        }

        // remove the extra 'R' added
        ans.pop_back();
        return ans;
    }
};