class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int left=0, right=s.length()-1;
        char temp;
        while(left < right)
        {
            if(isVowel(s[left]) == false) //increment left if s[left] is not a vowel
               left++;
            if(isVowel(s[right]) == false) //decrement right if s[right] is not a vowel
               right--;
            if(isVowel(s[left])==true && isVowel(s[right])==true) //swap s[left] and s[right] if both are vowel
            {
                temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
        }
        return s;
    }
};