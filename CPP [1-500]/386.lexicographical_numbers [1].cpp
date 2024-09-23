class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> lexicalOrder(int n) {
        vector<string> temp;
        for(int i=1; i<=n; i++)
            temp.push_back(to_string(i));

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(string& str: temp)
            ans.push_back(stoi(str));

        return ans;
    }
};  