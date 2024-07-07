class Solution {
private:
    void dfs(vector<string>& ans, string& curr, int n){
        if(n == 0)
        {
            ans.push_back(curr);
            return;
        }

        // 1 can be chosen without any restrictions
        curr += "1";
        dfs(ans, curr, n-1);
        curr.pop_back();

        // 0 can only be chosen if the string is empty 
        // or the previously chosen char was 1
        if(curr.empty() || curr.back() == '1')
        {
            curr += "0";
            dfs(ans, curr, n-1);
            curr.pop_back();
        }
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Backtracking
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";
        dfs(ans, curr, n);
        
        return ans;
    }
};