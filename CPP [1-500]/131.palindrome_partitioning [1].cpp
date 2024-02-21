class Solution {
public:
    bool isPalindrome(string& s)
    {
        int left=0, right=s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& ans, string& s, vector<string>& vec)
    {
        int n=s.length();
        if(n==0)
        {
            ans.push_back(vec);
            return;
        }
        for(int i=0; i<n; i++)
        {
            string left_substr = s.substr(0,i+1); //left substring
            string right_substr = s.substr(i+1); //right substring
            if(isPalindrome(left_substr)) //left substring is palindrome
            {
                vec.push_back(left_substr); //add left substring to vector
                solve(ans,right_substr,vec); //check for right substring
                vec.pop_back(); //pop back the left substring
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        solve(ans,s,vec);
        return ans;
    }
};