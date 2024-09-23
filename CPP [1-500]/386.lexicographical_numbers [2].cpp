class Solution {
private:
    static bool cmp(int a, int b){
        return to_string(a) < to_string(b);
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=n; i++)
            ans.push_back(i);

        sort(ans.begin(), ans.end(), cmp);
        
        return ans;
    }
};