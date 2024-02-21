class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1; i<=n/2; i++)
        {
            string a = to_string(i);
            string b = to_string(n-i);
            // char '0' is not found in both strings 'a' and 'b'
            if(a.find('0') == string::npos && b.find('0') == string::npos)
            {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
};