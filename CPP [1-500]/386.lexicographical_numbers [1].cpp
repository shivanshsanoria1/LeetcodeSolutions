class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n), sorting (with extra vector)
    vector<int> lexicalOrder(int n) {
        vector<string> temp;
        for(int i=1; i<=n; i++)
            temp.push_back(to_string(i));

        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(int i=1; i<=n; i++)
            ans.push_back(stoi(temp[i-1]));
        return ans;
    }
};  