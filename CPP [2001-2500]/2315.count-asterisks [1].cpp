class Solution {
public:
    int countAsterisks(string s) {
        int count = 0; // counts the num of '|' chars
        int ans = 0; // counts the num of '*' chars
        for(char ch: s)
        {
            if(ch == '|')
                count++;
            else if(ch == '*' && count % 2 == 0)
                ans++;
        }
        return ans;
    }
};