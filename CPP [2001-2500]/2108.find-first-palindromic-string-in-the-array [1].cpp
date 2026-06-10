class Solution {
private:
    bool isPalindrome(string& s){
        int left = 0, right = s.length() - 1;
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
    // T.C.=O(n*l), S.C.=O(1)
    // n: length of words[], l: max length of string in words[]
    string firstPalindrome(vector<string>& words) {
        for(string& word: words)
            if(isPalindrome(word))
                return word;
        return "";
    }
};