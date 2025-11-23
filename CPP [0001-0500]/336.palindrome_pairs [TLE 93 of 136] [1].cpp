class Solution {
private:
    // returns true if string 's' is palindrome
    bool isPalindrome(string s) {
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

public:
    // T.C.=O(l*n^2), S.C.=O(l)
    // n: size of words[], l: max-length of word in words[]
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i != j && isPalindrome(words[i] + words[j]))
                    ans.push_back({i, j});
        
        return ans;
    }
};