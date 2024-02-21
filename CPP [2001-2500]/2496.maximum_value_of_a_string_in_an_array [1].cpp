class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(string& str: strs)
        {
            int currVal = 0;
            string num = "";
            for(char ch: str)
            {
                if(ch < '0' || ch > '9') // str is alpha-numeric
                {
                    currVal = str.length();
                    break;
                }
                num += ch;
            }
            if(currVal == 0) // str is numeric
                currVal = stoi(num);
            ans = max(ans, currVal);
        }
        return ans;
    }
};