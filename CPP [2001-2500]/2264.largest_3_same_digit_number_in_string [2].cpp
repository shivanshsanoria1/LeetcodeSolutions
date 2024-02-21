class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i=1; i<num.length()-1; i++)
            if(num[i-1] == num[i] && num[i] == num[i+1])
            {
                string curr = "";
                curr += num[i-1];
                curr += num[i];
                curr += num[i+1];
                ans = max(ans, curr);
            }
        return ans;
    }
};