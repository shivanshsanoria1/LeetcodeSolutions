class Solution {
public:
    bool isPalindrome(string& s, int left, int right) //check if string s is palindrome from index left to right
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& ans, string& s, int left, vector<string>& vec)
    {
        int n=s.length();
        if(left==n)
        {
            ans.push_back(vec);
            return;
        }
        for(int right=left; right<n; right++) //left partition is from index [left,right] and right partition is from index [right+1,n-1]
            if(isPalindrome(s,left,right)) //left partition is palindrome
            {
                vec.push_back(s.substr(left,right-left+1)); //push the left partition in vector
                solve(ans,s,right+1,vec); //check for the right partition
                vec.pop_back(); //pop the left partition from vector
            }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        solve(ans,s,0,vec);
        return ans;
    }
};