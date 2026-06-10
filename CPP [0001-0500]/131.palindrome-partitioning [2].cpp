class Solution {
private:
    // retruns true if string 's' is palindrome 
    // in index-range [left, right]
    bool isPalindrome(string& s, int left, int right) {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& parts, vector<string>& part, string& s, int i) {
        int n=s.length();

        if(i == n)
        {
            parts.push_back(part);
            return;
        }

        // left-partition is in index-range [i, j] 
        // right-partition is in index-range [j+1, n-1]
        for(int j=i; j<n; j++) 
            // left-partition is palindrome
            if(isPalindrome(s, i, j)) 
            {
                // push the left-partition in vector
                part.push_back(s.substr(i, j-i+1)); 
                // check for the right-partition
                solve(parts, part, s, j+1); 
                // pop the left-partition from vector
                part.pop_back(); 
            }
    }

public:
    // T.C.=O(??), S.C.=O(??)
    // Backtracking
    vector<vector<string>> partition(string s) {
        vector<vector<string>> parts;
        vector<string> part;

        solve(parts, part, s, 0);
        
        return parts;
    }
};