class Solution {
public:
    // T.C.=O(n*w), S.C.=O(1)
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(const string& word: words){
            int sum = 0;
            for(char ch: word)
                sum = (sum + weights[ch - 'a']) % 26;
            ans += 'z' - sum;
        }

        return ans;
    }
};