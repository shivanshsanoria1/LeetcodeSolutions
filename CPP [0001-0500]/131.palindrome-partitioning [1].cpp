class Solution {
private:
    // returns true if string 's' is palindrome
    // and false otherwise
    bool isPalindrome(string& s) {
        int left = 0, right = s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& parts, vector<string>& part, string& s) {
        int n=s.length();

        if(n == 0)
        {
            parts.push_back(part);
            return;
        }

        for(int i=0; i<n; i++)
        {
            // left-substring is in index-range [0, i]
            string leftSubstr = s.substr(0, i+1); 
            // right-substring is in index-range [i+1, n-1]
            string rightSubstr = s.substr(i+1); 

            // left-substring is palindrome
            if(isPalindrome(leftSubstr)) 
            {
                // add left-substring curr-partition
                part.push_back(leftSubstr); 
                // check for the right-substring
                solve(parts, part, rightSubstr);
                // pop back the left-substring 
                part.pop_back(); 
            }
        }
    }

public:
    // T.C.=O(??), S.C.=O(??)
    // Backtracking
    vector<vector<string>> partition(string s) {
        vector<vector<string>> parts;
        vector<string> part;

        solve(parts, part, s);

        return parts;
    }
};