class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string compressedString(string word) {
        int n = word.length();
        string comp = "";
        int count = 1;
        
        for(int i=1; i<=n; i++)
        {
            if(i<n && word[i-1] == word[i])
            {
                count++;
                continue;
            }

            while(count > 9)
            {
                comp += "9";
                comp += word[i-1];
                count -= 9;
            }

            if(count > 0)
            {
                comp += to_string(count);
                comp += word[i-1];
            }

            // reset count
            count = 1;
        }

        return comp;
    }
};