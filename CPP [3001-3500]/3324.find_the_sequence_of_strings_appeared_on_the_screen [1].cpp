class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string curr = "";
        
        for(char ch: target)
        {
            // press key-1
            curr += 'a';
            ans.push_back(curr);

            // keep on pressing key-2 until the target char is reached
            for(char nextCh = 'b'; nextCh <= ch; nextCh++)
            {
                curr.back() = nextCh;
                ans.push_back(curr);
            }
        }

        return ans;
    }
};