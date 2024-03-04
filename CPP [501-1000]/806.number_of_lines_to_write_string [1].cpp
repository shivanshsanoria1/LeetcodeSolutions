class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lineCount = 1;
        int currLineWidth = 0;
        for(char ch: s)
        {
            int width = widths[ch - 'a'];
            if(currLineWidth + width <= 100)
                currLineWidth += width;
            else
            {
                lineCount++;
                currLineWidth = width;
            }
        }

        vector<int> ans(2);
        ans[0] = lineCount;
        ans[1] = currLineWidth;
        return ans;
    }
};