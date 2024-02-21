class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        if(n1 > n2) //s1 cannot be a substring of s2 if s1 is longer
            return false;
        vector<int> freq(26,0); //to store freq of char in s1
        for(int i=0; i<n1; i++)
            freq[s1[i]-'a']++;
        for(int i=0; i<n2; i++)
        {
            vector<int> freq_temp(26,0); //to store freq of char in substring of s2
            for(int j=i; j<n2 && j<i+n1; j++) //generate substring of length n1 starting at index i of s2
                freq_temp[s2[j]-'a']++;
            bool flag=false;
            for(int i=0; i<26; i++)
                if(freq[i] != freq_temp[i])
                {
                    flag=true;
                    break;
                }
            if(flag==false) //freq of char in s1 and freq of char in substring of s2 are equal
                return true;
        }
        return false;
    }
};