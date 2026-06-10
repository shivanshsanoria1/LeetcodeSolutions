class Solution {
public:
    bool isPalindrome(string s)
    {
        int left=0, right=s.length()-1;
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    string longestPalindrome(string s) { //T.C=O(n^3), S.C.=O(1)
        int n=s.length(), palin_len=0;
        string ans;
        for(int i=0; i<n; i++)
        {
            string temp;
            for(int j=i; j<n; j++)
            {
                temp=temp+s[j];
                if(temp.length()>palin_len && isPalindrome(temp)==true)
                {
                    ans=temp;
                    palin_len=temp.length();
                }
            }
        }
        return ans;
    }
};