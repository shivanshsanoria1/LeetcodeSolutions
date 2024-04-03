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
    
    void solve(vector<vector<string>>& ans, vector<string>& vec, string& s, int left) {
        int n=s.length();

        if(left == n)
        {
            ans.push_back(vec);
            return;
        }

        // left-partition is in index-range [left, right] 
        // right-partition is in index-range [right + 1, n-1]
        for(int right=left; right<n; right++) 
            // left-partition is palindrome
            if(isPalindrome(s, left, right)) 
            {
                // push the left-partition in vector
                vec.push_back(s.substr(left, right - left + 1)); 
                // check for the right-partition
                solve(ans, vec, s, right + 1); 
                // pop the left-partition from vector
                vec.pop_back(); 
            }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        solve(ans, vec, s, 0);
        return ans;
    }
};