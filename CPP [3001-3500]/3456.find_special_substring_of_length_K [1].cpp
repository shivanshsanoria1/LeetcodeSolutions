class Solution {
private:
    // returns true if the string of length k starting at index 'idx' 
    // is made up of only a single char
    bool isSingleCharString(string& s, int idx, int k){
        bool isValid = true;
        for(int i = idx + 1; i < idx + k; i++)
            if(s[i-1] != s[i])
            {
                isValid = false;
                break;
            }
        
        return isValid;
    }

public:
    // T.C.=O(n*k), S.C.=O(1)
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();

        for(int i=0; i<=n-k; i++)
        {
            if(i-1 >= 0 && s[i-1] == s[i])
                continue;
            if(i+k < n && s[i] == s[i+k])
                continue;
            
            if(isSingleCharString(s, i, k))
                return true;
        }

        return false;
    }
};