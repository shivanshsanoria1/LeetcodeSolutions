class Solution {
public:
    bool detectCapitalUse(string word) {
        int sum_lower=0, sum_upper=0; //freq of lowercase and uppercase letters
        for(int i=0; i<word.length(); i++)
        {
            if(word[i]>='a' && word[i]<='z')
                sum_lower++;
            else
                sum_upper++;
        }
        if(sum_upper==1 && word[0]>='A' && word[0]<='Z') //only 1 uppercase letter and its the 1st letter in the word
            return true;
        return (sum_lower>0 && sum_upper>0) ? false : true;
    }
};