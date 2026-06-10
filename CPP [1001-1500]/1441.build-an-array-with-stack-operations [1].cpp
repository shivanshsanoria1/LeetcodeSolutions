class Solution {
public:
    // T.C.=O(max(n, target.size())), S.C.=O(1)
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 0;
        for(int i=1; i<=n && idx < target.size(); i++)
        {
            if(i == target[idx])
            {
                ans.push_back("Push");
                idx++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};