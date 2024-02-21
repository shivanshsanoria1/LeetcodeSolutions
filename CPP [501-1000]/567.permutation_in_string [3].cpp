class Solution {
public:
    bool sameFreq(vector<int>& freq1, vector<int>& freq2)
    {
        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) { //sliding window
        int n1=s1.length(), n2=s2.length();
        if(n1 > n2) //s1 cannot be a substring of s2 if s1 is longer
            return false;
        vector<int> freq1(26,0); //to store freq of char in s1
        for(int i=0; i<n1; i++)
            freq1[s1[i]-'a']++;
        vector<int> freq2(26,0); //to store freq of char in substring (of length n1) of s2
        for(int i=0; i<n1; i++)
            freq2[s2[i]-'a']++;
        if(sameFreq(freq1,freq2)) //check if freq of s1 and freq of curr substring of s2 match
            return true;
        int left=0, right=n1;
        while(right < n2)
        {
            freq2[s2[left]-'a']--; //decrement the freq of char at index 'left' of s2
            freq2[s2[right]-'a']++; //increment the freq of char at index 'right' of s2
            if(sameFreq(freq1,freq2)) //check if freq of s1 and freq of curr substring of s2 match
                return true;
            left++;
            right++;
        }
        return false;
    }
};