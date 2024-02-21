class Solution {
public:
    bool sameFreq(vector<int>& freq1, vector<int>& freq2)
    {
        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        if(n1 > n2) //s1 cannot be a substring of s2 if s1 is longer
            return false;
        vector<int> freq1(26,0); //to store freq of char in s1
        for(int i=0; i<n1; i++)
            freq1[s1[i]-'a']++;
        vector<int> freq2(26,0); //to store freq of char in substring (of length n1) of s2
        for(int i=0; i<n1; i++) //generate substring of length n1 starting at index 0 of s2
            freq2[s2[i]-'a']++;
        if(sameFreq(freq1,freq2)) //check if freq of s1 and freq of curr substring of s2 match
            return true;
        for(int i=1; i+n1-1 < n2; i++) //generate substring of length n1 starting at index i of s2
        {
            freq2[s2[i-1]-'a']--; //decrement the freq of 1st char of prev substring
            freq2[s2[i+n1-1]-'a']++; //increment the freq of last char of curr substring
            if(sameFreq(freq1,freq2)) //check if freq of s1 and freq of curr substring of s2 match
                return true;
        }
        return false;
    }
};