class Solution {
public:
    // T.C.=O(2^n), S.C.=O(2^n)
    char kthCharacter(long long k, vector<int>& operations) {
        string word = "a";
        for(int op: operations)
        {
            if(op == 0)
                word += word;
            else // op == 1
            {
                string temp = word;
                for(char& ch: temp)
                    ch = (ch - 'a'+ 1) % 26 + 'a';
                word += temp;
            }
        }

        return word[k-1];
    }
};