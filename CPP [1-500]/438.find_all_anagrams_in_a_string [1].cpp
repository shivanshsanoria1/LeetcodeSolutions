class Solution {
public:
    bool sameFreq(vector<int>& freq1, vector<int>& freq2)
    {
        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;
        return true;
    }
    
    vector<int> findAnagrams(string s1, string s2) { //sliding window
        vector<int> ans;
        int n1=s1.length(), n2=s2.length();
        if(n2 > n1) //s2 cannot be a substring of s1 if s2 is longer
            return ans;
        vector<int> freq2(26,0); //to store freq of char in s2
        for(int i=0; i<n2; i++)
            freq2[s2[i]-'a']++;
        vector<int> freq1(26,0); //to store freq of char in substring (of length n2) of s1
        for(int i=0; i<n2; i++)
            freq1[s1[i]-'a']++;
        if(sameFreq(freq1,freq2)) //check if freq of s2 and freq of curr substring of s1 match
            ans.push_back(0);
        int left=0, right=n2;
        while(right < n1)
        {
            freq1[s1[left]-'a']--; //decrement the freq of char at index 'left' of s1
            freq1[s1[right]-'a']++; //increment the freq of char at index 'right' of s1
            left++;
            right++;
            if(sameFreq(freq1,freq2)) //check if freq of s2 and freq of curr substring of s1 match
                ans.push_back(left);
        }
        return ans;
    }
};