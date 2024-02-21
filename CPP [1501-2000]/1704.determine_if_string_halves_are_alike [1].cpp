class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        return false;
    }
    
    bool halvesAreAlike(string s) { //s is of even length
        int n=s.length();
        int left=n/2-1, right=n/2; //1st substring: [0,left] ; 2nd substring: [right,n-1]
        int left_vow=0, right_vow=0;
        for(int i=0; i<=left; i++) //count vowels in left half
            if(isVowel(s[i]))
                left_vow++;
        for(int i=right; i<n; i++) //count vowels in right half
            if(isVowel(s[i]))
                right_vow++;
        if(left_vow == right_vow)
            return true;
        return false;
    }
};