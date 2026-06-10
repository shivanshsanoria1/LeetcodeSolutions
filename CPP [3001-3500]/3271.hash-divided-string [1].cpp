class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string stringHash(string s, int k) {
        int n=s.length();
        string hash = "";

        for(int i=0; i<n; i += k)
        {
            int sum = 0;
            for(int j=i; j<i+k; j++)
                sum += s[j] - 'a';
            
            sum %= 26;
            hash += char(sum + 'a');
        }
        
        return hash;
    }
};